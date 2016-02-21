// message.c

varargs void message_vision(string msg, object me, object you)
{
	string my_gender, your_gender, my_name, your_name;
	string str1, str2, str3;

	if(!me) return;

	my_name= me->name();
	my_gender = me->query("gender");

	if(!my_name || !my_gender) return; //mon 10/23/97
	
	str1 = replace_string(msg,  "$P", gender_self(my_gender));
	str1 = replace_string(str1, "$N", gender_self(my_gender));
	str3 = replace_string(msg,  "$P", my_name);
	str3 = replace_string(str3, "$N", my_name);
	if( you ) {
		your_name= you->name();
		your_gender= you->query("gender");
		str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
		str2 = replace_string(str2, "$p", gender_self(your_gender));
		str2 = replace_string(str2, "$N", my_name);
		str2 = replace_string(str2, "$n", gender_self(your_gender));
		message("vision", str2, you);
		str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
		str1 = replace_string(str1, "$n", your_name);
		str3 = replace_string(str3, "$p", your_name);
		str3 = replace_string(str3, "$n", your_name);
	}
	message("vision", str1, me);
	if(environment(me)) { //mon 10/23/97
	  	if(you) 
		    message("vision", str3,  environment(me), ({ me, you}) );
		else
		    message("vision", str3,  environment(me), ({ me}));
	  	// broadcasting to remote rooms, snowcat feb 8 1998
	  	if(environment(me)->query("broadcast"))
	  		environment(me)->broadcast(str3);
	}
}

void tell_object(object ob, string str)
{
	if(ob) message("tell_object", str, ob);
}

varargs void tell_room(mixed ob, string str, object *exclude)
{
	if (ob) {
		message("tell_room", str, ob, exclude);
	  	// broadcasting to remote rooms, snowcat feb 8 1998
	  	if(ob->query("broadcast"))
	  		ob->broadcast(str);
	}  		
}

void shout(string str)
{
	message("shout", str, users(), this_player());
}

void write(string str)
{
	if( this_player() )
		message("write", str, this_player());
	else if( previous_object() )
		message("write", str, previous_object());
	else
		efun::write(str);
}

varargs void say(string str, mixed exclude)
{
	object ob = 0;
	if( living(previous_object()) ) 
		ob = previous_object();
	else if( this_player() ) 
		ob = this_player();
	if (ob && environment(ob)) {	
		message("say", str, environment(ob), ob);
  		// broadcasting to remote rooms, snowcat feb 8 1998
  		if(environment(ob)->query("broadcast"))
  			environment(ob)->broadcast(str);
  	}		
}

varargs void printf (string msg, mixed a1, mixed a2, mixed a3, mixed a4,
	 mixed a5, mixed a6, mixed a7, mixed a8, mixed a9, mixed a10,
	 mixed a11, mixed a12, mixed a13, mixed a14, mixed a15, mixed a16)
{
    msg = sprintf (msg,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16);
    
//    msg = CONVERT_D->output(msg,this_player());
    write (msg);
}

int notify_fail (mixed arg)
{
    if (stringp(arg))
        arg = (string) CONVERT_D->output(arg,this_player());
    return efun::notify_fail (arg);
}


