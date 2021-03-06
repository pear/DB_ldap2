<?php
// This script prints "skip" unless:
// * the mysql extension is built-in or loadable, AND
// * there is a database called "test" accessible
//   with no username/password, AND
// * we have create/drop privileges on the entire "test"
//   database
include './setup.inc';
require_once 'DB.php';
if (!defined('DRIVER_DSN') || DRIVER_DSN == '') {
    die("skip\n");
}
$db = DB::connect(DRIVER_DSN);
if (DB::isError($db)) {
    die("skip\n");
}
?>