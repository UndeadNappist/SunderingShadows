/*
  gmcp.c
  
  User.c inherit to add GMCP functionality.
  
  -- Tlaloc -- 9.16.21
*/

int gmcp_enabled = 0;       //Turns on if client has it enabled
mapping supports = ([  ]);  //Modules the client supports

//Prototyping
void update_status();

void gmcp_enable()
{
    write("<GMCP negotiation enabled.>\n");
    gmcp_enabled = 1;
}

//This handles message sent from client
void gmcp(string str)
{
    string cmd, arg;
    
    if(sscanf(str, "%s %s", cmd, arg) != 2)
        write("Command only; No argument specified.\n");
        
    write("<GMCP request received.>\n");
    write(str);
    write("\n\<GMCP request end.>\n");
}

//This sends message from game to client
void send_gmcp(string str)
{
    efun::send_gmcp(str);
}