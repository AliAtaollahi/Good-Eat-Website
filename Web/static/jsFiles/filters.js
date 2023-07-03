var changer1 = document.getElementById("changer1");
changer1.onclick = function () {
    var time1 = document.getElementById("time1");
    var time2 = document.getElementById("time2");
    if (time1.style.visibility == "hidden") {
        time1.style.visibility = "visible";
        time2.style.visibility = "visible";
    }
    else {
        time1.style.visibility = "hidden";
        time2.style.visibility = "hidden";
    }
}
var changer2 = document.getElementById("changer2");
changer2.onclick = function () {
    var rate1 = document.getElementById("rate1");
    var rate2 = document.getElementById("rate2");
    if (rate1.style.visibility == "hidden") {
        rate1.style.visibility = "visible";
        rate2.style.visibility = "visible";
    }
    else {
        rate1.style.visibility = "hidden";
        rate2.style.visibility = "hidden";
    }
}
var changer3 = document.getElementById("changer3");
changer3.onclick = function () {
    var tags = document.getElementById("tags");
    if (tags.style.visibility == "hidden")
        tags.style.visibility = "visible";
    else
        tags.style.visibility = "hidden";
}
document.getElementById("delete").onclick=function(){
    alert('you delete succusfully!');
    document.getElementById("deleteForm").submit();
}