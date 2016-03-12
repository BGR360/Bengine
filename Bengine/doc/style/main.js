function stickyHeader() {
    var originalHeaderHeight = 79;
    if ($(window).scrollTop() > originalHeaderHeight) {
        $('#navbar').addClass('fixed');
        $('#bottom_header').fadeOut();
    }
    else {
        $('#navbar').removeClass('fixed');
        $('#bottom_header').fadeIn();
    }
}

$(document).ready(function($) {
    $(window).scroll(function() {
        stickyHeader();
    });
});
