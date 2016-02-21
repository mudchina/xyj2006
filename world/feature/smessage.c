// message.c

#include <ansi.h>
#include <dbase.h>

#define MAX_MSG_BUFFER 500

static string *msg_buffer = ({});

void flush_buffer() {msg_buffer=({});}

void receive_message(string msgclass, string msg)
{
	string subclass, *ch;
	int len;

	if(!msg || (len=strlen(msg))<1) return;
	//added by mon 11/13/97 trying to prevent crash.

	if(len>8000) 
	  msg=msg[0..8000]+"\n\n．．．\n";
	  //added by mon 11/13/97 trying to prevent crash.

	msg = CONVERT_D->output(msg,this_object());

	if( !interactive(this_object()) ) {
		this_object()->relay_message(msgclass, msg);
		return;
	}

	if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 ) {
		switch(subclass) {
			case "channel":
				if( !pointerp(ch = query("channels"))
				||	member_array(msgclass, ch)==-1 )
					return;
				break;
			case "outdoor":
				if( !environment() || !environment()->query("outdoors") )
					return;
				break;
			default:
				error("Message: Invalid Subclass " + subclass + ".\n");
		}
	}

	if( query_temp("block_msg/all") || query_temp("block_msg/" + msgclass) )
		return;

	if( in_input(this_object()) || in_edit(this_object()) ) {
		if( sizeof(msg_buffer) < MAX_MSG_BUFFER )
			msg_buffer += ({ msg });
	} else
		receive( msg );
}

void write_prompt()
{
        string msg = "[输入时暂存讯息]\n" ;

	msg = CONVERT_D->output(msg,this_object());

	if( sizeof(msg_buffer) ) {
		receive(BOLD + msg + NOR);
		for(int i=0; i<sizeof(msg_buffer); i++)
			receive(msg_buffer[i]);
		msg_buffer = ({});
	}
	write("> ");
}

void receive_snoop(string msg)
{
    int encode=this_object()->query_temp("snoop_encoding");
    
    if(encode==1) // wiz is GB, player is BIG5
	msg=CONVERT_D->BIG2GB(msg);
    else if(encode==10) // wiz is BIG5, player is GB
	msg=CONVERT_D->GB2BIG(msg);

	if ( msg && msg!="" && msg[0]!='%' )
		receive("%" + msg);
}


