<?php

function errhandler($obj)
{
    if ($obj->getCode() == DB_ERROR) {
        print "  unknown: ".$obj->getUserInfo()."\n";
    } else {
        $msg = $obj->getMessage();
        print "  $msg";
        if (substr($msg, -1) != "\n") {
            print "\n";
        }
    }
}

$dbh->setErrorHandling(PEAR_ERROR_CALLBACK, "errhandler");

print "Trying to provoke DB_ERROR_ALREADY_EXISTS\n";
$dbh->query($test_mktable_query);

print "Trying to provoke DB_ERROR_NOSUCHTABLE\n";
$dbh->query(array("dc=nosuchobject,dc=example,dc=com", "action"=>"delete"));

print "Trying to provoke DB_ERROR_NOSUCHFIELD\n";
$dbh->query(array(array("dn"=>"cn=x,dc=example,dc=com", "nosuchfield"=>"x"), "action"=>"add"));

print "Trying to provoke DB_ERROR_CONSTRAINT\n";
$dbh->query(array(array("dn"=>"cn=x,dc=example,dc=com", "cn"=>"x"), "action"=>"add"));

print "Trying to provoke DB_ERROR_SYNTAX\n";
$dbh->query("SYNTAX TERROR");

?>
