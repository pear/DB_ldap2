--TEST--
DB_ldap2::fetchmode object
--SKIPIF--
<?php chdir(dirname(__FILE__)); require "skipif.inc"; ?>
--FILE--
<?php
require './connect.inc';
include '../fetchmode_object.inc';
?>
--EXPECT--
--- fetch with param DB_FETCHMODE_OBJECT ---
stdClass -> dn objectclass dc
stdClass -> dn objectclass dc
--- fetch with default fetchmode DB_FETCHMODE_OBJECT ---
stdClass -> dn objectclass dc
stdClass -> dn objectclass dc
--- fetch with default fetchmode DB_FETCHMODE_OBJECT and class DB_Row ---
db_row -> dn objectclass dc
db_row -> dn objectclass dc
