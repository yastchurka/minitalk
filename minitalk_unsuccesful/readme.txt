Here I tried to create a server/client version of minitalk,
where a client sends the whole string to the server,
server converts received bits to bytes and allocates them in the string,
and print entire string at once. 

To achieve that I had to solve several problems:
- getting the lenght of the string from the client
- allocating the size of the string with the null terminator
- allocating the bytes in the array
- printing the array

Unfortuantely allocating the bytes in the array turend out to be too complex.
Passing pointers and addresses between the functions and limitations of 
void function of sig_handler function was above my limitations.
Maybe I'll come back to solving this issue in the future or I'll leave it 
as it is with intention to track my progress.
