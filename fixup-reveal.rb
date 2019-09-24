# Fixes up the reveal.js presentation generated by Pandoc to use our custom
# Reveal.js settings..

jsRevealInit = %{
      Reveal.initialize({
        // Push each slide change to the browser history
        history: true,

        // Optional reveal.js plugins
        dependencies: [
          { src: './lib/js/classList.js', condition: function() { return !document.body.classList; } },
          { src: './plugin/zoom-js/zoom.js', async: true },
          { src: './plugin/notes/notes.js', async: true }
        ]
      });
}

newJsRevealInit = <<TEXTMARK
      
      Reveal.initialize({
        history: true,
        transition: 'fade',
        transitionSpeed: 'fast',
        center: false,
        autoPlayMedia: true,
        dependencies: [
          { src: './lib/js/classList.js', condition: function() { return !document.body.classList; } },
          { src: './plugin/zoom-js/zoom.js', async: true },
          { src: './plugin/notes/notes.js', async: true }
        ]
      });
TEXTMARK

cssLoad = %{
  <link rel="stylesheet" href="./css/theme/serif.css" id="theme">
}
newCssLoad = <<TEXTMARK

  <link rel="stylesheet" href="./css/theme/serif.css" id="theme">
  <style>
    .reveal h1 {
      font-size: 2em;
    }
    
  .reveal section img {
    box-shadow: none;
    background-color: transparent;
    border: none;
  }
  
  .reveal .slides section {
    transition-duration: 200ms !important; 
  }

  .sourceCode {
    margin-top: 0 !important;
    margin-bottom: 1em !important;
  }

  .smallFont {
    font-size: 0.46em !important;
  }

  .tinyFont {
    font-size: 0.4em !important;
  }

  .noMaxHeight {
    max-height: none !important;
  }

  .noMaxHeight > code {
    max-height: none !important;
  }

  .muted {
    opacity: 0.5 !important;
  }

  .float {
    float: left;
  }

  .halfWidth {
    width: 50% !important;
  }
  </style>
TEXTMARK

filename = ARGV[0]
h = File.read(filename)
h.gsub!(/\t/, '  ')
h.sub!(jsRevealInit, newJsRevealInit)
h.sub!(cssLoad, newCssLoad)

File.open(filename, "w") {|f| f.write(h)}
