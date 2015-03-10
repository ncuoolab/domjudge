<?php

/**
 * Batch functions in jury interface
 *
 * Part of the DOMjudge Programming Contest Jury System and licenced
 * under the GNU GPL. See README and COPYING for details.
 */

/**
 * Return form to batch creating team
 */
function addTeams()
{
    return
    addForm('edit.php') .
    '起始ID' .
    addInput('login_begin') .
    '結束ID' .
    addInput('login_end') .
    addHidden('table','team') .
    addHidden('referrer') .
    addHidden('cmd', 'batch_adding') .
    addSubmit('Create') .
    addSubmit('Cancel', 'cancel') .
    addEndForm();
}

function addTeamsFromCSV()
{
    return
    addForm('edit.php', $method = 'post', $id = '', $enctype = 'multipart/form-data') .
    addInputFile('csvFile') .
    addHidden('table','team') .
    addHidden('referrer') .
    addHidden('cmd', 'adding_from_csv') .
    addSubmit('Create') .
    addSubmit('Cancel', 'cancel') .
    addEndForm();
}
