'''Functions to process the ST[03] housekeeping parameter definitions.'''

import os
import jsonschema
from mako.template import Template
from mako.exceptions import text_error_template
from .utils import loadJson, perror


def generateConfig(missionConfig, outHeaderFile):
    '''Process the housekeeping parameter definitions and generate code'''
    schema = loadJson(configSchema)
    config = loadJson(missionConfig)
    jsonschema.validate(params, schema)
    generateCHeader(params, outHeaderFile)
    

class St03:
    '''Object with the service configuraton to pass to the Mako template'''
    config = None
    
    def __init__(self, config):
        '''Constructor'''
        self.config = config
    

def generate_st03_config(jsonDir, outDir):
    '''Generate the C files for the PUS ST[03] service configuration'''
    # File paths
    scriptDir = os.path.dirname(os.path.realpath(__file__))
    schemaFile = os.path.join(scriptDir, 'schemas', 'st03_schema.json')
    cTemplate = os.path.join(scriptDir, 'templates', 'st03_config.c.mako')
    missionFile = os.path.join(jsonDir, 'st03_config.json')
    outFile = os.path.join(outDir, 'st03_config.c')
    
    if not os.path.isfile(missionFile):
        raise Exception('ST[03] configuration file not found at {}'.format(missionFile))

    # Load and validate configuration
    print(' > generate configuration for service ST[03]')
    schema = loadJson(schemaFile)
    config = loadJson(missionFile)
    try:
        jsonschema.validate(config, schema)
    except Exception as err:
        perror('Error in ST[03] service configuration {}:\n{}'.format(missionFile, err))
        raise
        
    # Render template
    try:
        template = Template(filename=cTemplate)
        outStr = template.render(config=St03(config))
    except:
        perror(text_error_template().render())
        raise

    # Write file
    try:
        if not os.path.exists(outDir):
            os.makedirs(outDir)
        with open(outFile, 'w') as fd:
            fd.write(outStr)
    except Exception as err:
        perror('Error writing ST[03] generated code to {}:\n{}'.format(outFile, err))
        raise
