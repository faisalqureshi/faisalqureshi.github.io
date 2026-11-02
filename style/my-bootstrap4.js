$(document).ready(function(){

    $("#toggle-news").css('cursor', 'pointer');
    $("#toggle-about").css('cursor', 'pointer');
    $("#toggle-projects").css('cursor', 'pointer');

    // toggle news
    // the button sits at the bottom of #news-scroll; its labels come from data-more / data-less
    var newsExpanded = false;
    $("#toggle-news").click( function() {
        newsExpanded = !newsExpanded;
        $(".old-news").toggle(newsExpanded);
        $(this).html( newsExpanded ? $(this).data("less") : $(this).data("more") );
        // revealed items are interleaved by date, many near the top, so jump there
        $("#news-scroll").scrollTop(0);
    });

    // toggle about
    $("#toggle-about").click(function(){

        if ( $("#toggle-about").text() == "more >>>" ) {
            $(".about-more").each( function() {
                $(this).show()
            });
            $("#toggle-about").text("<<< less");
        }
        else {
            $(".about-more").each( function() {
                $(this).hide()
            });
            $("#toggle-about").text("more >>>");
        }
    });

    // toggle projects
    $("#toggle-projects").click(function(){

        if ( $("#toggle-projects").text() == "more >>>" ) {
            $(".projects-old").each( function() {
                $(this).show()
            });
            $("#toggle-projects").text("<<< less");
        }
        else {
            $(".projects-old").each( function() {
                $(this).hide()
            });
            $("#toggle-projects").text("more >>>");
        }
    });
});


$(document).ready(function(){
  // Add smooth scrolling to all links
  $("a").on('click', function(event) {

    // Make sure this.hash has a value before overriding default behavior
    //console.log(window.location.pathname)
    //console.log(this.pathname)
    //console.log(this.hash)

    if (this.hash !== "" && this.pathname == window.location.pathname) {
      // Prevent default anchor click behavior
      event.preventDefault();

      // Store hash
      var hash = this.hash;

      // Using jQuery's animate() method to add smooth page scroll
      // The optional number (800) specifies the number of milliseconds it takes to scroll to the specified area
      $('html, body').animate({
        scrollTop: $(hash).offset().top
      }, 800, function(){
   
        // Add hash (#) to URL when done scrolling (default click behavior)
        window.location.hash = hash;
      });
    } // End if
  });
});
