<?php

$dbh->setErrorHandling(PEAR_ERROR_DIE);
$dbh->query(
    array(
	array(
	    'dn' => 'cn=One,dc=example,dc=com',
	    'objectClass' => array('top', 'person'),
	    'cn' => 'One',
	    'sn' => 'One',
	    'description' => '1'
	), 
	'action' => 'add'
    )
);
$dbh->query(
    array(
	array(
	    'dn' => 'cn=Two,dc=example,dc=com',
	    'objectClass' => array('top', 'person'),
	    'cn' => 'Two',
	    'sn' => 'Two',
	    'description' => '2'
	), 
	'action' => 'add'
    )
);
$dbh->query(
    array(
	array(
	    'dn' => 'cn=Three,dc=example,dc=com',
	    'objectClass' => array('top', 'person'),
	    'cn' => 'Three',
	    'sn' => 'Three',
	    'description' => '3'
	), 
	'action' => 'add'
    )
);

print "testing fetchrow:\n";
$sth = $dbh->query("objectClass=*");
for ($i = 1; $i <= 5; $i++) {
    print "row $i: ";
    $row = $sth->fetchRow();
    if (DB::isError($row)) {
        print $row->toString() . "\n";
        continue;
    }
    if (0&&is_array($row)) {
        print implode(", ", $row) . "\n";
    } else {
        var_dump($row);
    }
}

$dbh->query(array(array('dn' => 'cn=One,dc=example,dc=com'), 'action' => 'delete'));
$dbh->query(array(array('dn' => 'cn=Two,dc=example,dc=com'), 'action' => 'delete'));
$dbh->query(array(array('dn' => 'cn=Three,dc=example,dc=com'), 'action' => 'delete'));

?>
