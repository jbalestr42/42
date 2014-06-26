$(document).ready(function(){
  $('.form-search').submit(function(){
    var keywd = $('.input-search').val();
/*
    if (keywd.indexOf(' ') !== -1)
      keywd = keywd.split(" ").join('~');
*/
    window.location= '/trombi/' + keywd;
    return false;
  });


});
