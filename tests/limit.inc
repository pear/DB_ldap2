<?php
error_reporting(E_ALL);
function pe($obj) {
    die($obj->getMessage() . "\n" . $obj->getDebugInfo());
}
$from    = 0;
$count   = 10;
$numrows = 30;

for ($i=0; $i<=$numrows+2; $i++) {
    $dbh->query(
	array(
	    array(
		'dn' => "cn=$i,dc=example,dc=com",
		'objectClass' => array('top', 'person'),
		'cn' => $i,
		'sn' => 'result',
	    ), 
	    'action' => 'add'
	)
    );
}
for ($i = 0; $i <= 3; $i++) {
    $from = 10 * $i;
    $res = $dbh->limitQuery("sn=result", $from, $count);
    echo "======= From: $from || Number of rows to fetch: $count =======\n";
    while ($row = $res->fetchRow()) {
        echo $res->getRowCounter() . '.- ' . $row["sn"] . ' ' . $row["cn"] . "\n";
    }
}
?>