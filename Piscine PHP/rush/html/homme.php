<?php
    if(!isset($_SESSION)) 
    { 
        session_start(); 
    } 
?>

<!DOCTYPE <!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Titou Shop</title>
    <link rel="stylesheet" type="text/css" media="screen" href="../css/header.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="../css/signup.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="../css/showcase.css" />
</head>
<body>
    <?php include("./header.php"); ?>
    <div id="feedback" class="feedback">
        <div class="feedback-content">
            <span class="close">&times;</span>
            <p id="login_message"></p>
            <p id="logout_message"></p>
        </div>
    </div>

<style>
.presentation {
    margin-top: 50px;
    justify-content: center;
    display: flex;
    flex-wrap: wrap;
}

.case {
    background-color: #4d4d4d;
    border: 1px solid #cccccc;
    border-radius: 10px;
    width: 250px;
    margin-left: 2%;
    margin-top: 2%;
    padding-left: 1%;
    padding-right: 1%;
    text-align: center;
    color: white;
    text-decoration: none;
    display: block;
}

.case img {
    width: 100%;
}

.case img:hover{
    transition: transform .5s;
    transform: scale(2);
}

.case img:active{
    transition: transform .200ms;
    transform: scale(1);
}

.case:hover, h1:hover {
    background-color: white;
    color: black;
}

</style>

<script>
    function ConfCom(){
        var n = confirm("Ajouter cet article au panier?");
        if  (n == true) {
        } else {
        }
    }
</script>

    <div class="presentation">
        <div class="case"><h1>Chemise Homme Blanche</h1><img src="../img/chemiseh1.jpg"></label><p>Prix</p><button onclick="ConfCom()">Ajouter au panier</button></div>
        <div class="case"><h1>Chemise Homme Blanche</h1><img src="../img/chemiseh2.jpg"><p>Prix</p></div>
        <div class="case"><h1>Chemise Homme Blanche</h1><img src="../img/chemiseh3.jpg"><p>Prix</p></div>
        <div class="case"><h1>Chemise Homme Blanche</h1><img src="../img/chemiseh4.jpg"><p>Prix</p></div>
        <div class="case"><h1>Chemise Homme Blanche</h1><img src="../img/chemiseh5.jpg"><p>Prix</p></div>
    </div>
    <script type="text/javascript" src="../js/modal.js"></script>
</body>
</html>