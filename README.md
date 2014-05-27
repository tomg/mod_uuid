#mod_uuid

This Apache module provides a random-based UUID environment variable for each request: `%{UUID}e`.

##Installation:

mod_uuid relies on the uuid library: on Debian/Ubuntu `apt-get install
uuid-dev` to get the header files then compile and install with the Apache
extension tool: apxs (apxs2 on some systems) `apxs -c -i -a mod_uuid.c`
