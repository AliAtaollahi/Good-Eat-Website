var exit=document.getElementById("exit");
exit.addEventListener("click",exitFunc);
function exitFunc () 
{
    if(confirm("Are you sure you want to exit"))
    document.getElementById("formExit").submit();
}
var filters_=document.getElementById("filters_");
filters_.onclick = function (){
    document.getElementById("filtersForm").submit();
}
var prevScrollpos = window.pageYOffset;
window.onscroll = function() {
var currentScrollPos = window.pageYOffset;
  if (prevScrollpos > currentScrollPos) {
    document.getElementsByClassName("topnav")[0].style.top = "20px";
  } else {
    document.getElementsByClassName("topnav")[0].style.top = "-50px";
  }
  prevScrollpos = currentScrollPos;
}