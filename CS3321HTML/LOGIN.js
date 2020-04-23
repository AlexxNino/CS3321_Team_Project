

function login(){
var username = document.getElementById("userName").value
var password = document.getElementById("password").value

if ( username == "admin" && password == "password"){
    alert ("Login successfully");
    window.location = "adminPage.html"; // Redirecting to other page.


    
    return false;
    }
if ( username == "student" && password == "password"){
    alert ("Login successfully");
    window.location = "StudentView.html"; // Redirecting to other page.
    
    return false;
    }

}