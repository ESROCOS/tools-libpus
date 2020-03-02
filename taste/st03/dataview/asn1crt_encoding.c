#include <string.h>
#include <assert.h>
#include <math.h>
#include <float.h>

#include "asn1crt_encoding.h"



static byte masks[] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };
static byte masksb[] = { 0x0, 0x1, 0x3, 0x7, 0xF, 0x1F, 0x3F, 0x7F, 0xFF };

static asn1SccUint32 masks2[] = { 0x0,
0xFF,
0xFF00,
0xFF0000,
0xFF000000 };

/***********************************************************************************************/
/*   Bit Stream Functions                                                                      */
/***********************************************************************************************/

flag OctetString_equal(int len1, int len2, const byte arr1[], const byte arr2[])
{
	return (len1 == len2) && (memcmp(arr1, arr2, len1) == 0);
}

flag BitString_equal(int nBitsLength1, int nBitsLength2, const byte arr1[], const byte arr2[])
{
	return
		(nBitsLength1 == nBitsLength2) &&
		(nBitsLength1 / 8 == 0 || memcmp(arr1, arr2, nBitsLength1 / 8) == 0) &&
		(nBitsLength1 % 8 > 0 ? (arr1[nBitsLength1 / 8] >> (8 - nBitsLength1 % 8) == arr2[nBitsLength1 / 8] >> (8 - nBitsLength1 % 8)) : TRUE);
}


void BitStream_Init(BitStream* pBitStrm, unsigned char* buf, long count)
{
	pBitStrm->count = count;
	pBitStrm->buf = buf;
	memset(pBitStrm->buf, 0x0, (size_t)count);
	pBitStrm->currentByte = 0;
	pBitStrm->currentBit = 0;
}

void BitStream_AttachBuffer(BitStream* pBitStrm, unsigned char* buf, long count)
{
	pBitStrm->count = count;
	pBitStrm->buf = buf;
	pBitStrm->currentByte = 0;
	pBitStrm->currentBit = 0;
}

asn1SccSint BitStream_GetLength(BitStream* pBitStrm)
{
	int ret = pBitStrm->currentByte;
	if (pBitStrm->currentBit)
		ret++;
	return ret;
}


void BitStream_AppendBitOne(BitStream* pBitStrm)
{
	pBitStrm->buf[pBitStrm->currentByte] |= masks[pBitStrm->currentBit];

	if (pBitStrm->currentBit<7)
		pBitStrm->currentBit++;
	else {
		pBitStrm->currentBit = 0;
		pBitStrm->currentByte++;
	}
	assert(pBitStrm->currentByte * 8 + pBitStrm->currentBit <= pBitStrm->count * 8);
}

void BitStream_AppendBitZero(BitStream* pBitStrm)
{
	if (pBitStrm->currentBit<7)
		pBitStrm->currentBit++;
	else {
		pBitStrm->currentBit = 0;
		pBitStrm->currentByte++;
	}
	assert(pBitStrm->currentByte * 8 + pBitStrm->currentBit <= pBitStrm->count * 8);
}

void BitStream_AppendNBitZero(BitStream* pBitStrm, int nbits)
{
	int totalBits = pBitStrm->currentBit + nbits;
	pBitStrm->currentBit = totalBits % 8;
	pBitStrm->currentByte += totalBits / 8;
}

void BitStream_AppendNBitOne(BitStream* pBitStrm, int nbits)
{
	int i;

	while (nbits >= 8) {
		BitStream_AppendByte(pBitStrm, 0xFF, FALSE);
		nbits -= 8;
	}
	for (i = 0; i<nbits; i++)
		BitStream_AppendBitOne(pBitStrm);

}

void BitStream_AppendBits(BitStream* pBitStrm, const byte* srcBuffer, int nbits)
{
	int i = 0;
	byte lastByte = 0;

	while (nbits >= 8) {
		BitStream_AppendByte(pBitStrm, srcBuffer[i], FALSE);
		nbits -= 8;
		i++;
	}
	if (nbits > 0) {
		lastByte = (byte)(srcBuffer[i] >> (8 - nbits));
		BitStream_AppendPartialByte(pBitStrm, lastByte, (byte)nbits, FALSE);
	}
}

void BitStream_AppendBit(BitStream* pBitStrm, flag v)
{
	if (v)
		pBitStrm->buf[pBitStrm->currentByte] |= masks[pBitStrm->currentBit];

	if (pBitStrm->currentBit<7)
		pBitStrm->currentBit++;
	else {
		pBitStrm->currentBit = 0;
		pBitStrm->currentByte++;
	}
	assert(pBitStrm->currentByte * 8 + pBitStrm->currentBit <= pBitStrm->count * 8);
}


flag BitStream_ReadBit(BitStream* pBitStrm, flag* v)
{
	*v = pBitStrm->buf[pBitStrm->currentByte] & masks[pBitStrm->currentBit];

	if (pBitStrm->currentBit<7)
		pBitStrm->currentBit++;
	else {
		pBitStrm->currentBit = 0;
		pBitStrm->currentByte++;
	}
	return pBitStrm->currentByte * 8 + pBitStrm->currentBit <= pBitStrm->count * 8;
}

void BitStream_AppendByte(BitStream* pBitStrm, byte v, flag negate)
{
	int cb = pBitStrm->currentBit;
	int ncb = 8 - cb;
	if (negate)
		v = (byte)~v;
	pBitStrm->buf[pBitStrm->currentByte++] |= (byte)(v >> cb);

	assert(pBitStrm->currentByte * 8 + pBitStrm->currentBit <= pBitStrm->count * 8);

	if (cb)
		pBitStrm->buf[pBitStrm->currentByte] |= (byte)(v << ncb);

}

void BitStream_AppendByte0(BitStream* pBitStrm, byte v)
{
	int cb = pBitStrm->currentBit;
	int ncb = 8 - cb;

	pBitStrm->buf[pBitStrm->currentByte++] |= (byte)(v >> cb);

	assert(pBitStrm->currentByte * 8 + pBitStrm->currentBit <= pBitStrm->count * 8);

	if (cb)
		pBitStrm->buf[pBitStrm->currentByte] |= (byte)(v << ncb);

}


flag BitStream_ReadByte(BitStream* pBitStrm, byte* v)
{
	int cb = pBitStrm->currentBit;
	int ncb = 8 - pBitStrm->currentBit;
	*v = (byte)(pBitStrm->buf[pBitStrm->currentByte++] << cb);

	if (cb) {
		*v |= (byte)(pBitStrm->buf[pBitStrm->currentByte] >> ncb);
	}

	return pBitStrm->currentByte * 8 + pBitStrm->currentBit <= pBitStrm->count * 8;
}

flag BitStream_ReadBits(BitStream* pBitStrm, byte* BuffToWrite, int nbits)
{
	int i = 0;

	while (nbits >= 8) {
		if (!BitStream_ReadByte(pBitStrm, &BuffToWrite[i]))
			return FALSE;
		nbits -= 8;
		i++;
	}

	if (nbits > 0) {
		if (!BitStream_ReadPartialByte(pBitStrm, &BuffToWrite[i], (byte)nbits))
			return FALSE;
		BuffToWrite[i] = (byte)(BuffToWrite[i] << (8 - nbits));
	}

	return TRUE;
}

/* nbits 1..7*/
void BitStream_AppendPartialByte(BitStream* pBitStrm, byte v, byte nbits, flag negate)
{
	int cb = pBitStrm->currentBit;
	int totalBits = cb + nbits;
	int totalBitsForNextByte;
	if (negate)
		v = masksb[nbits] & ((byte)~v);

	if (totalBits <= 8) {
		pBitStrm->buf[pBitStrm->currentByte] |= (byte)(v << (8 - totalBits));
		pBitStrm->currentBit += nbits;
		if (pBitStrm->currentBit == 8) {
			pBitStrm->currentBit = 0;
			pBitStrm->currentByte++;
		}
	}
	else {
		totalBitsForNextByte = totalBits - 8;
		pBitStrm->buf[pBitStrm->currentByte++] |= (byte)(v >> totalBitsForNextByte);
		pBitStrm->buf[pBitStrm->currentByte] |= (byte)(v << (8 - totalBitsForNextByte));
		pBitStrm->currentBit = totalBitsForNextByte;
	}
	assert(pBitStrm->currentByte * 8 + pBitStrm->currentBit <= pBitStrm->count * 8);

}

/* nbits 1..7*/
flag BitStream_ReadPartialByte(BitStream* pBitStrm, byte *v, byte nbits)
{
	int cb = pBitStrm->currentBit;
	int totalBits = cb + nbits;
	int totalBitsForNextByte;

	if (totalBits <= 8) {
		*v = (byte)((pBitStrm->buf[pBitStrm->currentByte] >> (8 - totalBits)) & masksb[nbits]);
		pBitStrm->currentBit += nbits;
		if (pBitStrm->currentBit == 8) {
			pBitStrm->currentBit = 0;
			pBitStrm->currentByte++;
		}
	}
	else {
		totalBitsForNextByte = totalBits - 8;
		*v = (byte)(pBitStrm->buf[pBitStrm->currentByte++] << totalBitsForNextByte);
		*v |= (byte)(pBitStrm->buf[pBitStrm->currentByte] >> (8 - totalBitsForNextByte));
		*v &= masksb[nbits];
		pBitStrm->currentBit = totalBitsForNextByte;
	}
	return pBitStrm->currentByte * 8 + pBitStrm->currentBit <= pBitStrm->count * 8;
}




/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
/*   Integer Functions                                                                     */
/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/



static void BitStream_EncodeNonNegativeInteger32Neg(BitStream* pBitStrm,
	asn1SccUint32 v,
	flag negate)
{
	int cc;
	asn1SccUint32 curMask;
	int pbits;

	if (v == 0)
		return;

	if (v<0x100) {
		cc = 8;
		curMask = 0x80;
	}
	else if (v<0x10000) {
		cc = 16;
		curMask = 0x8000;
	}
	else if (v<0x1000000) {
		cc = 24;
		curMask = 0x800000;
	}
	else {
		cc = 32;
		curMask = 0x80000000;
	}

	while ((v & curMask) == 0) {
		curMask >>= 1;
		cc--;
	}

	pbits = cc % 8;
	if (pbits) {
		cc -= pbits;
		BitStream_AppendPartialByte(pBitStrm, (byte)(v >> cc), (byte)pbits, negate);
	}

	while (cc) {
		asn1SccUint32 t1 = v & masks2[cc >> 3];
		cc -= 8;
		BitStream_AppendByte(pBitStrm, (byte)(t1 >> cc), negate);
	}

}

static flag BitStream_DecodeNonNegativeInteger32Neg(BitStream* pBitStrm,
	asn1SccUint32* v,
	int nBits)
{
	byte b;
	*v = 0;
	while (nBits >= 8) {
		*v <<= 8;
		if (!BitStream_ReadByte(pBitStrm, &b))
			return FALSE;
		*v |= b;
		nBits -= 8;
	}
	if (nBits)
	{
		*v <<= nBits;
		if (!BitStream_ReadPartialByte(pBitStrm, &b, (byte)nBits))
			return FALSE;
		*v |= b;
	}

	return TRUE;
}



void BitStream_EncodeNonNegativeInteger(BitStream* pBitStrm, asn1SccUint v)
{

#if WORD_SIZE==8
	if (v<0x100000000LL)
		BitStream_EncodeNonNegativeInteger32Neg(pBitStrm, (asn1SccUint32)v, 0);
	else {
		asn1SccUint32 hi = (asn1SccUint32)(v >> 32);
		asn1SccUint32 lo = (asn1SccUint32)v;
		int nBits;
		BitStream_EncodeNonNegativeInteger32Neg(pBitStrm, hi, 0);

		nBits = GetNumberOfBitsForNonNegativeInteger(lo);
		BitStream_AppendNBitZero(pBitStrm, 32 - nBits);
		BitStream_EncodeNonNegativeInteger32Neg(pBitStrm, lo, 0);
	}
#else
	BitStream_EncodeNonNegativeInteger32Neg(pBitStrm, v, 0);
#endif
}


flag BitStream_DecodeNonNegativeInteger(BitStream* pBitStrm, asn1SccUint* v, int nBits)
{
#if WORD_SIZE==8
	asn1SccUint32 hi = 0;
	asn1SccUint32 lo = 0;
	flag ret;

	if (nBits <= 32)
	{
		ret = BitStream_DecodeNonNegativeInteger32Neg(pBitStrm, &lo, nBits);
		*v = lo;
		return ret;
	}

	ret = BitStream_DecodeNonNegativeInteger32Neg(pBitStrm, &hi, 32) && BitStream_DecodeNonNegativeInteger32Neg(pBitStrm, &lo, nBits - 32);

	*v = hi;
	*v <<= nBits - 32;
	*v |= lo;
	return ret;
#else
	return BitStream_DecodeNonNegativeInteger32Neg(pBitStrm, v, nBits);
#endif
}


void BitStream_EncodeNonNegativeIntegerNeg(BitStream* pBitStrm, asn1SccUint v, flag negate)
{
#if WORD_SIZE==8
	if (v<0x100000000LL)
		BitStream_EncodeNonNegativeInteger32Neg(pBitStrm, (asn1SccUint32)v, negate);
	else {
		int nBits;
		asn1SccUint32 hi = (asn1SccUint32)(v >> 32);
		asn1SccUint32 lo = (asn1SccUint32)v;
		BitStream_EncodeNonNegativeInteger32Neg(pBitStrm, hi, negate);

		/*bug !!!!*/
		if (negate)
			lo = ~lo;
		nBits = GetNumberOfBitsForNonNegativeInteger(lo);
		BitStream_AppendNBitZero(pBitStrm, 32 - nBits);
		BitStream_EncodeNonNegativeInteger32Neg(pBitStrm, lo, 0);
	}
#else
	BitStream_EncodeNonNegativeInteger32Neg(pBitStrm, v, negate);
#endif
}

static int GetNumberOfBitsForNonNegativeInteger32(asn1SccUint32 v)
{
	int ret = 0;

	if (v<0x100) {
		ret = 0;
	}
	else if (v<0x10000) {
		ret = 8;
		v >>= 8;
	}
	else if (v<0x1000000) {
		ret = 16;
		v >>= 16;
	}
	else {
		ret = 24;
		v >>= 24;
	}
	while (v>0) {
		v >>= 1;
		ret++;
	}
	return ret;
}

int GetNumberOfBitsForNonNegativeInteger(asn1SccUint v)
{
#if WORD_SIZE==8
	if (v<0x100000000LL)
		return GetNumberOfBitsForNonNegativeInteger32((asn1SccUint32)v);
	else {
		asn1SccUint32 hi = (asn1SccUint32)(v >> 32);
		return 32 + GetNumberOfBitsForNonNegativeInteger32(hi);
	}
#else
	return GetNumberOfBitsForNonNegativeInteger32(v);
#endif
}

int GetLengthInBytesOfUInt(asn1SccUint64 v)
{
	int ret = 0;
	asn1SccUint32 v32 = (asn1SccUint32)v;
#if WORD_SIZE==8
	if (v>0xFFFFFFFF) {
		ret = 4;
		v32 = (asn1SccUint32)(v >> 32);
	}
#endif

	if (v32<0x100)
		return ret + 1;
	if (v32<0x10000)
		return ret + 2;
	if (v32<0x1000000)
		return ret + 3;
	return ret + 4;
}

static int GetLengthSIntHelper(asn1SccUint v)
{
	int ret = 0;
	asn1SccUint32 v32 = (asn1SccUint32)v;
#if WORD_SIZE==8
	if (v>0x7FFFFFFF) {
		ret = 4;
		v32 = (asn1SccUint32)(v >> 32);
	}
#endif

	if (v32 <= 0x7F)
		return ret + 1;
	if (v32 <= 0x7FFF)
		return ret + 2;
	if (v32 <= 0x7FFFFF)
		return ret + 3;
	return ret + 4;
}

int GetLengthInBytesOfSInt(asn1SccSint v)
{
	if (v >= 0)
		return GetLengthSIntHelper((asn1SccUint)v);

	return GetLengthSIntHelper((asn1SccUint)(-v - 1));
}



void BitStream_EncodeConstraintWholeNumber(BitStream* pBitStrm, asn1SccSint v, asn1SccSint min, asn1SccSint max)
{
	int nRangeBits;
	int nBits;
	asn1SccUint range;
	assert(min <= max);
	range = (asn1SccUint)(max - min);
	if (!range)
		return;
	nRangeBits = GetNumberOfBitsForNonNegativeInteger(range);
	nBits = GetNumberOfBitsForNonNegativeInteger((asn1SccUint)(v - min));
	BitStream_AppendNBitZero(pBitStrm, nRangeBits - nBits);
	BitStream_EncodeNonNegativeInteger(pBitStrm, (asn1SccUint)(v - min));
}

void BitStream_EncodeConstraintPosWholeNumber(BitStream* pBitStrm, asn1SccUint v, asn1SccUint min, asn1SccUint max)
{
	int nRangeBits;
	int nBits;
	asn1SccUint range;
	assert(min <= v);
	assert(v <= max);
	range = (asn1SccUint)(max - min);
	if (!range)
		return;
	nRangeBits = GetNumberOfBitsForNonNegativeInteger(range);
	nBits = GetNumberOfBitsForNonNegativeInteger(v - min);
	BitStream_AppendNBitZero(pBitStrm, nRangeBits - nBits);
	BitStream_EncodeNonNegativeInteger(pBitStrm, v - min);
}


flag BitStream_DecodeConstraintWholeNumber(BitStream* pBitStrm, asn1SccSint* v, asn1SccSint min, asn1SccSint max)
{
	asn1SccUint uv;
	int nRangeBits;
	asn1SccUint range = (asn1SccUint)(max - min);

	ASSERT_OR_RETURN_FALSE(min <= max);


	*v = 0;
	if (!range) {
		*v = min;
		return TRUE;
	}

	nRangeBits = GetNumberOfBitsForNonNegativeInteger(range);


	if (BitStream_DecodeNonNegativeInteger(pBitStrm, &uv, nRangeBits))
	{
		*v = ((asn1SccSint)uv) + min;
		return TRUE;
	}
	return FALSE;
}

flag BitStream_DecodeConstraintPosWholeNumber(BitStream* pBitStrm, asn1SccUint* v, asn1SccUint min, asn1SccUint max)
{
	asn1SccUint uv;
	int nRangeBits;
	asn1SccUint range = max - min;

	ASSERT_OR_RETURN_FALSE(min <= max);


	*v = 0;
	if (!range) {
		*v = min;
		return TRUE;
	}

	nRangeBits = GetNumberOfBitsForNonNegativeInteger(range);

	if (BitStream_DecodeNonNegativeInteger(pBitStrm, &uv, nRangeBits))
	{
		*v = uv + min;
		return TRUE;
	}
	return FALSE;
}


void BitStream_EncodeSemiConstraintWholeNumber(BitStream* pBitStrm, asn1SccSint v, asn1SccSint min)
{
	int nBytes;
	assert(v >= min);
	nBytes = GetLengthInBytesOfUInt((asn1SccUint)(v - min));

	/* encode length */
	BitStream_EncodeConstraintWholeNumber(pBitStrm, nBytes, 0, 255); /*8 bits, first bit is always 0*/
																	 /* put required zeros*/
	BitStream_AppendNBitZero(pBitStrm, nBytes * 8 - GetNumberOfBitsForNonNegativeInteger((asn1SccUint)(v - min)));
	/*Encode number */
	BitStream_EncodeNonNegativeInteger(pBitStrm, (asn1SccUint)(v - min));
}

void BitStream_EncodeSemiConstraintPosWholeNumber(BitStream* pBitStrm, asn1SccUint v, asn1SccUint min)
{
	int nBytes;
	assert(v >= min);
	nBytes = GetLengthInBytesOfUInt(v - min);

	/* encode length */
	BitStream_EncodeConstraintWholeNumber(pBitStrm, nBytes, 0, 255); /*8 bits, first bit is always 0*/
																	 /* put required zeros*/
	BitStream_AppendNBitZero(pBitStrm, nBytes * 8 - GetNumberOfBitsForNonNegativeInteger(v - min));
	/*Encode number */
	BitStream_EncodeNonNegativeInteger(pBitStrm, (v - min));
}


flag BitStream_DecodeSemiConstraintWholeNumber(BitStream* pBitStrm, asn1SccSint* v, asn1SccSint min)
{
	asn1SccSint nBytes;
	int i;
	*v = 0;
	if (!BitStream_DecodeConstraintWholeNumber(pBitStrm, &nBytes, 0, 255))
		return FALSE;
	for (i = 0; i<nBytes; i++) {
		byte b = 0;
		if (!BitStream_ReadByte(pBitStrm, &b))
			return FALSE;
		*v = (*v << 8) | b;
	}
	*v += min;
	return TRUE;
}

flag BitStream_DecodeSemiConstraintPosWholeNumber(BitStream* pBitStrm, asn1SccUint* v, asn1SccUint min)
{
	asn1SccSint nBytes;
	int i;
	*v = 0;
	if (!BitStream_DecodeConstraintWholeNumber(pBitStrm, &nBytes, 0, 255))
		return FALSE;
	for (i = 0; i<nBytes; i++) {
		byte b = 0;
		if (!BitStream_ReadByte(pBitStrm, &b))
			return FALSE;
		*v = (*v << 8) | b;
	}
	*v += min;
	return TRUE;
}


void BitStream_EncodeUnConstraintWholeNumber(BitStream* pBitStrm, asn1SccSint v)
{
	int nBytes = GetLengthInBytesOfSInt(v);

	/* encode length */
	BitStream_EncodeConstraintWholeNumber(pBitStrm, nBytes, 0, 255); /*8 bits, first bit is always 0*/

	if (v >= 0) {
		BitStream_AppendNBitZero(pBitStrm, nBytes * 8 - GetNumberOfBitsForNonNegativeInteger((asn1SccUint)v));
		BitStream_EncodeNonNegativeInteger(pBitStrm, (asn1SccUint)(v));
	}
	else {
		BitStream_AppendNBitOne(pBitStrm, nBytes * 8 - GetNumberOfBitsForNonNegativeInteger((asn1SccUint)(-v - 1)));
		BitStream_EncodeNonNegativeIntegerNeg(pBitStrm, (asn1SccUint)(-v - 1), 1);
	}
}

flag BitStream_DecodeUnConstraintWholeNumber(BitStream* pBitStrm, asn1SccSint* v)
{
	asn1SccSint nBytes;
	int i;
	flag valIsNegative = FALSE;
	*v = 0;


	if (!BitStream_DecodeConstraintWholeNumber(pBitStrm, &nBytes, 0, 255))
		return FALSE;


	for (i = 0; i<nBytes; i++) {
		byte b = 0;
		if (!BitStream_ReadByte(pBitStrm, &b))
			return FALSE;
		if (!i) {
			valIsNegative = b>0x7F;
			if (valIsNegative)
				*v = -1;
		}
		*v = (*v << 8) | b;
	}
	return TRUE;
}



#ifndef INFINITY
#ifdef __GNUC__
#define INFINITY (__builtin_inf())
#endif
#endif

/*
Bynary encoding will be used
REAL = M*B^E
where
M = S*N*2^F

ENCODING is done within three parts
part 1 is 1 byte header
part 2 is 1 or more byte for exponent
part 3 is 3 or more byte for mantissa (N)

First byte
S :0-->+, S:1-->-1
Base will be always be 2 (implied by 6th and 5th bit which are zero)
ab: F  (0..3)
cd:00 --> 1 byte for exponent as 2's complement
cd:01 --> 2 byte for exponent as 2's complement
cd:10 --> 3 byte for exponent as 2's complement
cd:11 --> 1 byte for encoding the length of the exponent, then the expoent

8 7 6 5 4 3 2 1
+-+-+-+-+-+-+-+-+
|1|S|0|0|a|b|c|d|
+-+-+-+-+-+-+-+-+
*/

#if FP_WORD_SIZE==8

#define ExpoBitMask  0x7FF0000000000000ULL
#define MantBitMask  0x000FFFFFFFFFFFFFULL
#define MantBitMask2 0xFFE0000000000000ULL
#define MantisaExtraBit 0x0010000000000000ULL
#else				 

#define ExpoBitMask  0x7F800000U
#define MantBitMask  0x007FFFFFU
#define MantBitMask2 0xF0000000U
#define MantisaExtraBit 0x00800000U

#endif


void CalculateMantissaAndExponent(asn1Real d, int* exponent, asn1SccUint64* mantissa)
{

#if FP_WORD_SIZE==8
	union {
		asn1Real in;
		asn1SccUint64 out;
	} double2uint;
	asn1SccUint64 ll = 0;
#else
	union {
		asn1Real in;
		asn1SccUint32 out;
	} double2uint;
	asn1SccUint32 ll = 0;
#endif

	double2uint.in = d;
	ll = double2uint.out;

	*exponent = 0;
	*mantissa = 0;

#if FP_WORD_SIZE==8
	* exponent = (int)(((ll & ExpoBitMask) >> 52) - 1023 - 52);
	*mantissa = ll & MantBitMask;
	(*mantissa) |= MantisaExtraBit;
#else
	*exponent = (int)(((ll & ExpoBitMask) >> 23) - 127 - 23);

	*mantissa = ll & MantBitMask;
	(*mantissa) |= MantisaExtraBit;
#endif
}

asn1Real GetDoubleByMantissaAndExp(asn1SccUint mantissa, int exponent)
{
	asn1Real ret = 1.0;
	if (mantissa == 0)
		return 0.0;

	if (exponent >= 0) {
		while (exponent) {
			ret = ret * 2.0;
			exponent--;
		}
		return (asn1Real)mantissa*ret;
	}
	else {
		exponent = -exponent;
		while (exponent) {
			ret = ret * 2.0;
			exponent--;
		}
		return ((asn1Real)mantissa) / ret;
	}
}




void BitStream_EncodeReal(BitStream* pBitStrm, asn1Real v)
{
	byte header = 0x80;
	int nExpLen;
	int nManLen;
	int exponent;
	asn1SccUint64 mantissa;


	if (v == 0.0)
	{
		BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 0xFF);
		return;
	}

	if (v == INFINITY)
	{
		BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 0xFF);
		BitStream_EncodeConstraintWholeNumber(pBitStrm, 0x40, 0, 0xFF);
		return;
	}

	if (v == -INFINITY)
	{
		BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 0xFF);
		BitStream_EncodeConstraintWholeNumber(pBitStrm, 0x41, 0, 0xFF);
		return;
	}
	if (v < 0) {
		header |= 0x40;
		v = -v;
	}

	CalculateMantissaAndExponent(v, &exponent, &mantissa);
	nExpLen = GetLengthInBytesOfSInt(exponent);
	nManLen = GetLengthInBytesOfUInt(mantissa);
	assert(nExpLen <= 3);
	if (nExpLen == 2)
		header |= 1;
	else if (nExpLen == 3)
		header |= 2;


	/* encode length */
	BitStream_EncodeConstraintWholeNumber(pBitStrm, 1 + nExpLen + nManLen, 0, 0xFF);

	/* encode header */
	BitStream_EncodeConstraintWholeNumber(pBitStrm, header, 0, 0xFF);

	/* encode exponent */
	if (exponent >= 0) {
		BitStream_AppendNBitZero(pBitStrm, nExpLen * 8 - GetNumberOfBitsForNonNegativeInteger((asn1SccUint)exponent));
		BitStream_EncodeNonNegativeInteger(pBitStrm, (asn1SccUint)exponent);
	}
	else {
		BitStream_AppendNBitOne(pBitStrm, nExpLen * 8 - GetNumberOfBitsForNonNegativeInteger((asn1SccUint)(-exponent - 1)));
		BitStream_EncodeNonNegativeIntegerNeg(pBitStrm, (asn1SccUint)(-exponent - 1), 1);
	}


	/* encode mantissa */
	BitStream_AppendNBitZero(pBitStrm, nManLen * 8 - GetNumberOfBitsForNonNegativeInteger((asn1SccUint)(mantissa)));
	BitStream_EncodeNonNegativeInteger(pBitStrm, mantissa);

}

flag DecodeRealAsBinaryEncoding(BitStream* pBitStrm, int length, byte header, asn1Real* v);

flag BitStream_DecodeReal(BitStream* pBitStrm, asn1Real* v)
{
	byte header;
	byte length;

	if (!BitStream_ReadByte(pBitStrm, &length))
		return FALSE;
	if (length == 0)
	{
		*v = 0.0;
		return TRUE;
	}

	if (!BitStream_ReadByte(pBitStrm, &header))
		return FALSE;

	if (header == 0x40)
	{
		*v = INFINITY;
		return TRUE;
	}

	if (header == 0x41)
	{
		*v = -INFINITY;
		return TRUE;
	}

	return DecodeRealAsBinaryEncoding(pBitStrm, length - 1, header, v);
}


flag DecodeRealAsBinaryEncoding(BitStream* pBitStrm, int length, byte header, asn1Real* v)
{
	int sign = 1;
	/*int base=2;*/
	int F;
	unsigned factor = 1;
	int expLen;
	int exponent = 0;
	int expFactor = 1;
	asn1SccUint N = 0;
	int i;

	if (header & 0x40)
		sign = -1;
	if (header & 0x10) {
		/*base = 8;*/
		expFactor = 3;
	}
	else if (header & 0x20) {
		/*base = 16;*/
		expFactor = 4;
	}

	F = (header & 0x0C) >> 2;
	factor <<= F;

	expLen = (header & 0x03) + 1;

	if (expLen>length)
		return FALSE;

	for (i = 0; i<expLen; i++) {
		byte b = 0;
		if (!BitStream_ReadByte(pBitStrm, &b))
			return FALSE;
		if (!i) {
			if (b>0x7F)
				exponent = -1;
		}
		exponent = exponent << 8 | b;
	}
	length -= expLen;

	for (i = 0; i<length; i++) {
		byte b = 0;
		if (!BitStream_ReadByte(pBitStrm, &b))
			return FALSE;
		N = N << 8 | b;
	}


	/*  *v = N*factor * pow(base,exp);*/
	*v = GetDoubleByMantissaAndExp(N*factor, expFactor*exponent);

	if (sign<0)
		*v = -(*v);


	return TRUE;
}



