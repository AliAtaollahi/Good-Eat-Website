var div_ = document.getElementById("div_");
div_.onload = unfade();
function unfade() {
    var op = 0.1;  // initial opacity
    div_.style.display = 'block';
    var timer = setInterval(function () {
        if (op >= 1) {
            clearInterval(timer);
        }
        div_.style.opacity = op;
        div_.style.filter = 'alpha(opacity=' + op * 100 + ")";
        op += op * 0.1;
    }, 15);
}
var see=document.getElementById("see");
var password_=document.getElementById("password");
see.onclick=function(){
    if(password_.type== "text")
    {
        password_.type="password";
        see.style.backgroundImage="url('unseen.png')";
    }
    else
    {
        password_.type="text";
        see.style.backgroundImage="url('seen.png')";
    }
}