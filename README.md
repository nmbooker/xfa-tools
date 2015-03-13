# xfa-tools
Tool to extract XFA data from a PDF.

This is aimed at developers who wish to develop a parser for XFA,
or at users who want to get what data they can out in a
format that can be read in a text editor.

## xfa-extract

Takes PDF filename on command line, and extracts the XFA data as
an array of pairs in JSON.  I chose an array of pairs because I don't
yet know whether it's possible that keys can be duplicated - I've only
introspected one PDF file so far at the time of writing.

Here's an example of how to get the template out in human-readable
format (assuming you also have `jq` and `xmllint` installed in your `$PATH`):

```
% ./xfa-extract ../vat101i-notes.pdf \
    | ./json-alist-to-object \
    | jq -r '.template' \
    | xmllint --format - > ../template.xml
```

You can then open the template.xml file in a text editor, or run it
through a dedicated parser.

## json-alist-to-object

This is a simple filter that takes a JSON array of pairs on STDIN
and outputs a JSON object.

## Copyright and License

Copyright (C) 2015 Nicholas Martin Booker

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
