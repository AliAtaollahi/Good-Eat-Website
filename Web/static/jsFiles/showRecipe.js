var changer1 = document.getElementById("changer1");
changer1.onclick = function () {
    var textBoxId = document.getElementById("textBoxId");
    var textBoxIdSubmit=document.getElementById("textBoxIdSubmit");
    if (textBoxId.style.visibility == "hidden")
    {
        textBoxId.style.visibility = "visible";
        textBoxIdSubmit.style.visibility = "visible";
    }
    else
    {
        textBoxId.style.visibility = "hidden";
        textBoxIdSubmit.style.visibility = "hidden";
    }
}
var changer2 = document.getElementById("changer2");
changer2.onclick = function () {
    var rate = document.getElementById("rate");
    var rateSubmit=document.getElementById("rateSubmit");
    if (rate.style.visibility == "hidden")
    {
        rate.style.visibility = "visible";
        rateSubmit.style.visibility = "visible";
    }
    else
    {
        rate.style.visibility = "hidden";
        rateSubmit.style.visibility = "hidden";
    }
}