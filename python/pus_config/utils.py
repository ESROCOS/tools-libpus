import sys
import simplejson as json

def loadJson(fpath):
    '''Load a JSON file'''
    try:
        with open(fpath) as fd:
            return json.load(fd)
    except Exception as err:
        perror('Error loading JSON file {}:\n{}'.format(fpath, err))
        raise

def perror(msg):
    '''Print a message to stderr'''
    print(msg, file=sys.stderr)


