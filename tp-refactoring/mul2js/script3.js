
function mul2(n) {
    return n*2;
}

function make_handler(id, sn){
    var id = document.getElementById(id);
    var sp = document.getElementById(sn);
    return function(){
        sp.innerHTML = mul2(id.value);
    };
    
}

