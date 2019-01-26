var modal = document.getElementById('feedback');
var modal_content = document.getElementsByClassName("feedback-content")[0];
var btn = document.getElementById("createacc");
var span = document.getElementsByClassName("close")[0];
var signup_message = document.getElementById("signup_message");
var login_message = document.getElementById("login_message");
var logout_message = document.getElementById("logout_message");
var signup = document.getElementById("signup");
var login = document.getElementById("login");
var logout = document.getElementById("logout_flag");

if (signup && signup.textContent)
{
    if (signup.textContent == "OUI")
    {
        signup_message.textContent = "Successfully signed up";
        modal_content.style.backgroundColor = "darkgreen";
    }
    else
    {
        signup_message.textContent = "Failed sign up";
        modal_content.style.backgroundColor = "darkred";
    }
    modal.style.display = "block";
    
    span.onclick = function() {
        modal.style.display = "none";
    }
    
    window.onclick = function(event) {
        if (event.target == modal) {
            modal.style.display = "none";
        }
    }
}

else if (login && login.textContent)
{    
    if (login.textContent == "OUI")
    {
        login_message.textContent = "Successfully logged in";
        modal_content.style.backgroundColor = "darkgreen";
    }
    else
    {
        login_message.textContent = "Wrong username or password";
        modal_content.style.backgroundColor = "darkred";
    }
    modal.style.display = "block";
    
    span.onclick = function() {
        modal.style.display = "none";
    }
    
    window.onclick = function(event) {
        if (event.target == modal) {
            modal.style.display = "none";
        }
    }
}

else if (logout && logout.textContent)
{    
    if (logout.textContent == "OUI")
    {
        logout_message.textContent = "Successfully logged out";
        modal_content.style.backgroundColor = "darkgreen";
    }
    else
    {
        login_message.textContent = "An error occured";
        modal_content.style.backgroundColor = "darkred";
    }
    modal.style.display = "block";
    
    span.onclick = function() {
        modal.style.display = "none";
    }
    
    window.onclick = function(event) {
        if (event.target == modal) {
            modal.style.display = "none";
        }
    }
}