<?php

$dbh->setErrorHandling(PEAR_ERROR_DIE);

print "testing fetchmodes: fetchrow default default\n";
$sth = $dbh->query("objectClass=*");
$row = $sth->fetchRow();
var_dump($row);

print "testing fetchmodes: fetchinto default default\n";
$sth = $dbh->query("objectClass=*");
$row = array();
$sth->fetchInto($row);
var_dump($row);

print "testing fetchmodes: fetchrow ordered default\n";
$dbh->setFetchMode(DB_FETCHMODE_ORDERED);
$sth = $dbh->query("objectClass=*");
$row = $sth->fetchRow();
var_dump($row);

print "testing fetchmodes: fetchrow assoc default\n";
$dbh->setFetchMode(DB_FETCHMODE_ASSOC);
$sth = $dbh->query("objectClass=*");
$row = $sth->fetchRow();
var_dump($row);

print "testing fetchmodes: fetchrow ordered default with assoc specified\n";
$dbh->setFetchMode(DB_FETCHMODE_ORDERED);
$sth = $dbh->query("objectClass=*");
$row = $sth->fetchRow(DB_FETCHMODE_ASSOC);
var_dump($row);

print "testing fetchmodes: fetchrow assoc default with ordered specified\n";
$dbh->setFetchMode(DB_FETCHMODE_ASSOC);
$sth = $dbh->query("objectClass=*");
$row = $sth->fetchRow(DB_FETCHMODE_ORDERED);
var_dump($row);

print "testing fetchmodes: fetchinto ordered default\n";
$dbh->setFetchMode(DB_FETCHMODE_ORDERED);
$sth = $dbh->query("objectClass=*");
$row = array();
$sth->fetchInto($row);
var_dump($row);

print "testing fetchmodes: fetchinto assoc default\n";
$dbh->setFetchMode(DB_FETCHMODE_ASSOC);
$sth = $dbh->query("objectClass=*");
$row = array();
$sth->fetchInto($row);
var_dump($row);

print "testing fetchmodes: fetchinto ordered default with assoc specified\n";
$dbh->setFetchMode(DB_FETCHMODE_ORDERED);
$sth = $dbh->query("objectClass=*");
$row = array();
$sth->fetchInto($row, DB_FETCHMODE_ASSOC);
var_dump($row);

print "testing fetchmodes: fetchinto assoc default with ordered specified\n";
$dbh->setFetchMode(DB_FETCHMODE_ASSOC);
$sth = $dbh->query("objectClass=*");
$row = array();
$sth->fetchInto($row, DB_FETCHMODE_ORDERED);
var_dump($row);

?>
