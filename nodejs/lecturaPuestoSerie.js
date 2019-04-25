var sys = require("sys"),
    repl = require("repl"),
    serialPort = require("serialport");

    // Create new serialport pointer
    var serial = new serialPort("COM3" , { baudRate : 9600 });

    // Add data read event listener
    serial.on( "data", function( chunk ) {
        sys.puts(chunk);
    });


    serial.on( "error", function( msg ) {
        sys.puts("error: " + msg );
    });

    repl.start( "=>" );