--TEST--
DB_ldap2::error mapping
--SKIPIF--
<?php chdir(dirname(__FILE__)); require "skipif.inc"; ?>
<?php if (version_compare(phpversion(), "4.3.0") < 0) die("skip\n"); ?>
--FILE--
<?php
require "connect.inc";
require "mktable.inc";
require "../errors.inc";
?>
--EXPECT--
Trying to provoke DB_ERROR_ALREADY_EXISTS
Trying to provoke DB_ERROR_NOSUCHTABLE
  DB Error: no such table
Trying to provoke DB_ERROR_NOSUCHFIELD
  DB Error: no such field
Trying to provoke DB_ERROR_CONSTRAINT
  DB Error: constraint violation
Trying to provoke DB_ERROR_SYNTAX
  DB Error: syntax error
