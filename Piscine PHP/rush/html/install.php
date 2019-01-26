<?php
session_start();
$servername = "mysql";
$username = "rootuser";
$password = "rootpswd";
$my_db = "testdb";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $my_db);
// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Create database
$sql = "CREATE DATABASE Boutique";

// sql to create table
$sql = "CREATE TABLE Clients (
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
    firstname VARCHAR(30) NOT NULL,
    lastname VARCHAR(30) NOT NULL,
    email VARCHAR(50),
    passwd VARCHAR(30)
    )";

require_once("./index.php");

mysqli_close($conn);
?>