--TEST--
DB_ldap2::error mapping (PHP < 4.3.0)
--SKIPIF--
<?php chdir(dirname(__FILE__)); require "skipif.inc"; ?>
<?php if (version_compare(phpversion(), "4.3.0") >= 0) die("skip\n"); ?>
--FILE--
<?php
require "connect.inc";
require "mktable.inc";
require "../errors.inc";
?>
--EXPECT--
Trying to provoke DB_ERROR_ALREADY_EXISTS
LDAP: Already exists
  DB Error: already exists
Trying to provoke DB_ERROR_NOSUCHTABLE
LDAP: No such object
	matched DN: "dc=example,dc=com"
  DB Error: no such table
Trying to provoke DB_ERROR_NOSUCHFIELD
LDAP: Undefined attribute type
	additional info: nosuchfield: attribute type undefined
  DB Error: no such field
Trying to provoke DB_ERROR_CONSTRAINT
LDAP: Object class violation
	additional info: no objectClass attribute
  DB Error: constraint violation
Trying to provoke DB_ERROR_SYNTAX
  DB Error: syntax error
