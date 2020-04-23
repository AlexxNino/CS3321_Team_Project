<?php

$dbc = @mysqli_connect("localhost", "studentdb", "Password", "school")
or die('Could not connect' . mysqli_connect_error());

if(isset($_POST['submit'])){
    $semester = $_POST['semester'];
}

$semester = 'FALL_2019';

$query = "SELECT course_name, Course_Number, student_id,grade,Semester FROM grades WHERE student_id = 10001 AND Semester = 'FALL_2019' ";

$response = @mysqli_query($dbc, $query);

if ($response) {
    echo '<table align="left"
    cellspacing="5" cellpadding="8">
    
    <td align="left"><b>course_name</b></td>
    <td align="left"><b>Course_Number</b></td>
    <td align="left"><b>student_id </b></td>
    <td align="left"><b>grade</b></td>
    <td align="left"><b>semester</b></td>
    ';

    while ($row = mysqli_fetch_array($response)) {
        echo '<tr><td align="left"/>' .
            $row['course_name'] . '</td><td align="left">' .
            $row['Course_Number'] . '</td><td align="left">' .
            $row['student_id'] . '</td><td align="left">' .
            $row['grade'] . '</td><td align="left">' .
            $row['semester'] . '</td><td align="left">';

        echo '</tr>';
    }

    echo '</table>';
} else {
    echo "coudlnt issue databse query";
    echo mysqli_error($dbc);
}

mysqli_close($dbc);

?>
