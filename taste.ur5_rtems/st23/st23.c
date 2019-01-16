/*
* H2020 ESROCOS Project
* Company: GMV Aerospace & Defence S.A.U.
* Licence: GPLv2
*/

/* User code: This file will not be overwritten by TASTE. */

#include "st23.h"
#include <stdio.h>
#include "pus_types.h"
#include "pus_error.h"

#include "pus_st23_packets.h"

void st23_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void st23_PI_tc23(const asn1SccPusPacket *IN_tcPacket)
{
    /* Write your code here! */
	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	errorCode = PUS_EXPECT_ST23TC(IN_tcPacket, pusSubtype_NONE);
	if(PUS_NO_ERROR == errorCode )
	{
		//send 1.1
		subtype = pus_TM_1_1_successfulAcceptance;
		st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);


		pusSubservice_t subtype = pus_getTcSubtype(IN_tcPacket);
		if( pus_TC_23_1_createFile == subtype )
		{
			pusSt23FileName_t file;
			pusSt23RepositoryPath_t repository;
			pusSt23MaximumSize_t maxSize;
			errorCode = pus_tc_tm_23_X_getFileName(&file, IN_tcPacket);
			if(PUS_NO_ERROR != errorCode)
			{
				subtype = pus_TM_1_4_failedStart;
				st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
				return;
			}
			errorCode = pus_tc_tm_23_X_getRepositoryPath(&repository, IN_tcPacket);
			if(PUS_NO_ERROR != errorCode)
			{
				subtype = pus_TM_1_4_failedStart;
				st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
				return;
			}
			errorCode = pus_tc_tm_23_1_4_getMaximumSize(&maxSize, IN_tcPacket);
			if(PUS_NO_ERROR != errorCode)
			{
				subtype = pus_TM_1_4_failedStart;
				st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
				return;
			}

			subtype = pus_TM_1_3_successfulStart;
			st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);

			st23_RI_create(&repository, &file, &maxSize, &errorCode);
		}
		else if( pus_TC_23_2_deleteFile == subtype )
		{
			pusSt23FileName_t file;
			pusSt23RepositoryPath_t repository;
			errorCode = pus_tc_tm_23_X_getFileName(&file, IN_tcPacket);
			if(PUS_NO_ERROR != errorCode)
			{
				subtype = pus_TM_1_4_failedStart;
				st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
				return;
			}
			errorCode = pus_tc_tm_23_X_getRepositoryPath(&repository, IN_tcPacket);
			if(PUS_NO_ERROR != errorCode)
			{
				subtype = pus_TM_1_4_failedStart;
				st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
				return;
			}

			subtype = pus_TM_1_3_successfulStart;
			st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);

			st23_RI_delete(&repository, &file, &errorCode);
		}
		else if( pus_TC_23_3_reportFileAttributes == subtype )
		{
			pusSt23FileName_t file;
			pusSt23RepositoryPath_t repository;
			pusSt23MaximumSize_t maxSize;
			errorCode = pus_tc_tm_23_X_getFileName(&file, IN_tcPacket);
			if(PUS_NO_ERROR != errorCode)
			{
				subtype = pus_TM_1_4_failedStart;
				st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
				return;
			}
			errorCode = pus_tc_tm_23_X_getRepositoryPath(&repository, IN_tcPacket);
			if(PUS_NO_ERROR != errorCode)
			{
				subtype = pus_TM_1_4_failedStart;
				st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
				return;
			}

			subtype = pus_TM_1_3_successfulStart;
			st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);

			st23_RI_getAttributes(&repository, &file, &maxSize, &errorCode);
			if(PUS_NO_ERROR == errorCode)
			{
				pusPacket_t tm;
				pusApid_t apid, destination;
				pusSequenceCount_t seqCount;

				st23_RI_getApid(&apid);
				st23_RI_getSequenceCount(&seqCount);
				destination = pus_getApid(IN_tcPacket);

				errorCode = pus_tm_23_4_createReportFileAtributesReport(&tm, apid, seqCount, destination, &repository, &file, maxSize);
				if( PUS_NO_ERROR == errorCode)
				{
					st23_RI_newTm(&tm);
				}
			}
		}
		else if( pus_TC_23_14_copyFile == subtype )
		{
			pusSt23FileName_t fileSource, fileTarget;
			pusSt23RepositoryPath_t repositorySource, repositoryTarget;
			errorCode = pus_tc_23_14_getSourceFileName(&fileSource, IN_tcPacket);
			if(PUS_NO_ERROR != errorCode)
			{
				subtype = pus_TM_1_4_failedStart;
				st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
				return;
			}
			errorCode = pus_tc_23_14_getTargetFileName(&fileTarget, IN_tcPacket);
			if(PUS_NO_ERROR != errorCode)
			{
				subtype = pus_TM_1_4_failedStart;
				st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
				return;
			}
			errorCode = pus_tc_23_14_getSourceRepositoryPath(&repositorySource, IN_tcPacket);
			if(PUS_NO_ERROR != errorCode)
			{
				subtype = pus_TM_1_4_failedStart;
				st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
				return;
			}
			errorCode = pus_tc_23_14_getTargetRepositoryPath(&repositoryTarget, IN_tcPacket);
			if(PUS_NO_ERROR != errorCode)
			{
				subtype = pus_TM_1_4_failedStart;
				st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
				return;
			}

			subtype = pus_TM_1_3_successfulStart;
			st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);

			st23_RI_copy(&repositorySource, &fileSource, &repositoryTarget, &fileTarget, &errorCode);
		}
		else
		{
			errorCode = PUS_ERROR_TC_SUBTYPE;
		}

	}
	else
	{
		errorCode = PUS_ERROR_TC_SERVICE;

		//send 1.2
		subtype = pus_TM_1_2_failedAcceptance;
		st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
		return;
	}

	if( PUS_NO_ERROR == errorCode)
	{
		//send 1.7
		subtype = pus_TM_1_7_successfulCompletion;
		st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
	else
	{
		//send 1.8
		subtype = pus_TM_1_8_failedCompletion;
		st23_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}

}

