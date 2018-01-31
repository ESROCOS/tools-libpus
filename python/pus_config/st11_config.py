# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

'''Functions to process the ST[11] housekeeping parameter definitions.'''

import os
import jsonschema
from mako.template import Template
from mako.exceptions import text_error_template
from .utils import loadJson, perror


def generate_st11_config(jsonDir, outDir):
    '''Generate the C files for the PUS ST[11] service configuration'''
    # File paths
    scriptDir = os.path.dirname(os.path.realpath(__file__))
    schemaFile = os.path.join(scriptDir, 'schemas', 'st11_schema.json')
    headerTemplate = os.path.join(scriptDir, 'templates', 'pus_st11_config.h.mako')
    srcTemplate = os.path.join(scriptDir, 'templates', 'pus_st11_config.c.mako')
    missionFile = os.path.join(jsonDir, 'st11_config.json')

    outHeaderFile = os.path.join(outDir, 'include', 'pus_st11_config.h')
    outSrcFile = os.path.join(outDir, 'src', 'pus_st11_config.c')
    
    if not os.path.isfile(missionFile):
        raise Exception('ST[11] configuration file not found at {}'.format(missionFile))

    # Load and validate configuration
    print(' - generate configuration for service ST[11]')
    schema = loadJson(schemaFile)
    configData = loadJson(missionFile)
    try:
        jsonschema.validate(configData, schema)
    except Exception as err:
        perror('Error in ST[11] service configuration {}:\n{}'.format(missionFile, err))
        raise
        
    # Render templates
    try:
        template = Template(filename=headerTemplate)
        outHeader = template.render(config=configData,tempvars=dict())
    except:
        perror('Error generating {}:'.format(headerTemplate))
        perror(text_error_template().render())
        raise

    try:
        template = Template(filename=srcTemplate)
        outSrc = template.render(config=configData,tempvars=dict())
    except:
        perror('Error generating {}:'.format(outSrcFile))
        perror(text_error_template().render())
        raise

    # Write file
    try:
        if not os.path.exists(os.path.dirname(outHeaderFile)):
            os.makedirs(os.path.dirname(outHeaderFile))
        with open(outHeaderFile, 'w') as fd:
            fd.write(outHeader)
    except Exception as err:
        perror('Error writing ST[11] generated code to {}:\n{}'.format(outHeaderFile, err))
        raise

    try:
        if not os.path.exists(os.path.dirname(outSrcFile)):
            os.makedirs(os.path.dirname(outSrcFile))
        with open(outSrcFile, 'w') as fd:
            fd.write(outSrc)
    except Exception as err:
        perror('Error writing ST[11] generated code to {}:\n{}'.format(outSrcFile, err))
        raise
