<?php

$dbh->setErrorHandling(PEAR_ERROR_DIE);
$sth = $dbh->simpleQuery("objectClass=*");
print gettype($sth)."\n";

?>
