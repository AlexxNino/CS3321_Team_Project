<?php
$dbc = @mysqli_connect("localhost", "studentdb", "Password", "school")
OR die('Could not connect'.mysqli_connect_error());

$query = "SELECT Course_name, Course_Number, Teacher_Name ";

$response = @mysqli_query($dbc,$query);


if($response){
    echo '<table align="left"
    cellspacing="5" cellpadding="8">
    
    <td align="left"><b>Course Name</b></td>
    <td align="left"><b>Course Number</b></td>
    <td align="left"><b>Teacher Name </b></td>';

    while ($row = mysqli_fetch_array($response)){
        echo '<tr><td align="left"/>'.
            $row['Course_name'].'</td><td align="left">'.
            $row['Course_Number'].'</td><td align="left">'.
            $row['Teacher_Name'].'</td><td align="left">';

        echo '</tr>';
    }

    echo '</table>';
}   else{
    echo "coudlnt issue databse query";
    echo mysqli_error($dbc);
}

mysqli_close($dbc);


?>