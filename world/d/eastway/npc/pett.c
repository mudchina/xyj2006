// pet.c writted by Beeby. 07/28/2000

inherit NPC;
inherit F_SAVE;

private string SAVE_NAME="pet_save";
private static int can_save=1;

//void try_move();

void create()
{	
	seteuid(getuid());	
        set_name("宠物", ({"pet"}) );
        set("gender", "女性");
	set("race","野兽");
        set("age", 1);
	set("base_name","兔");
        set("attitude", "friendly");
        set("long","小家伙。\n");
        set("combat_exp", 1);
	set("str",3);
	set("owner","dad");
	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
//  	set("verbs", ({ "bite"}));
  	set("ride/msg", "骑");
  	set("ride/dodge", 35);
	set_skill("unarmed",10);
  	set_temp("apply/attack", 80);
  	set_temp("apply/armor", 80);

	set("is_pet",1);


        setup();
}

void reset()
{
        if( !environment() ||  //mon 2/4/98
                ! find_living(query("owner")) )
        {
                destruct(this_object());
                return;
        }
}

void die()
{
	message_vision("远处传来一呼哨，$N一下子就窜得没影了。\n",this_object());
	destruct(this_object());
}

void unconcious()
{
	return die();
}

string query_save_file()
{
        string id;
        id = query("owner");
        if( !id ) return 0;
        return sprintf(DATA_DIR"pet/%c/%s", id[0], id);
}


void init()
{	seteuid(getuid());
	add_action("do_kill",({"kill","fight","steal"}));
	add_action("do_get","get");
	add_action("do_drop","drop");
	add_action("do_mount","mount");

}

int do_mount(string arg)
{
     object me=this_object(),who=this_player(),env;
     if(!arg) return 0;
     env = environment(who);
     if(present(arg,env)!=me) return 0;
     if(me->query("owner")==who->query("id")) return 0;
     message_vision("$n左躲右闪，$N累得满头大汗也没骑上去。\n",who,me);
     return 1;
}

int do_drop(string arg)
{
     object me=this_object(),who=this_player(),env;
     if(!arg) return 0;
     env = environment(who);
     if(present(arg,who)!=me) return 0;
     if(me->move(env)) {
       message_vision("$N把$n从怀里放了下来。\n",who,me);
       return 1;
     }
     return 0;
}

int do_get(string arg)
{    object me=this_object(),who=this_player(),env;
     
     if(!arg) return 0;
     env = environment(who);
     if(present(arg,env)!=me) return 0;
     if(who->query("id")==me->query("owner"))
      {
      if(me->move(who)) {
       message_vision("$N弯下腰把$n抱了起来，搂在怀里。\n",who,me);
      } else {
       message_vision("$N弯下腰一抱却没把$n抱起来，小家伙好沉哪！\n",who,me);
      }
     } else {
      message_vision("$N蹲下身朝$n伸开双手，$n却一下子闪开了．．．\n",who,me);
     }
     return 1;
}

int do_kill(string arg)
{       
	object me,who;
	string name,verb,what,obj;
	if (!arg) return 0;
	verb=query_verb();
	me=this_player();
	
	if(verb=="steal") {
	  if(sscanf(arg, "%s from %s", what, obj)!=2 ) 
	    return 0;
          }
        else obj=arg;

	if(!objectp(who=present(obj,environment(me))) 
	   || !living(who)) return 0;

	if(who==this_object()) {
	  switch(verb) {
	    case "kill":
	      tell_object(environment(this_object()),
	        who->query("name")+"拼命地哭了起来：主人，"+
                me->query("name")+"要杀我．．．快回来呀！\n");
	      break;
            case "fight":

	      tell_object(environment(this_object()),
		who->query("name")+"哭了起来：主人，"+
                me->query("name")+"要抢我的糖吃．．．快回来呀！\n");
              break;
	    case "steal":

	      tell_object(environment(this_object()),
		who->query("name")+"哭了起来：主人，"+
		me->query("name")+"要偷吃我的糖！\n");
              break;
          }
        }
        command(verb);
	return 0;
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "kick":
           	command("say 主人～～，主人～～，"  + ob->query("name") + "踢我耶！");
		command("kick " + ob->query("id"));
                        break;
        case "slap":
                command("say 主人～～，主人～～，"  + ob->query("name") +
"打我耶，好痛啊～～～～");
                command("slap " + ob->query("id"));
                        break;
	case "hit":
                command("pain " + ob->query("id"));
                        break;
        case "bite":
                command("face " + ob->query("id"));
                        break;  
        case "papaya":
                command("pout");
                        break;  

                }
}

void relay_whisper(object me, string msg)
{
        if (me->query("id")!=query("owner"))
        {
                message_vision((string)this_object()->query("name")
                        + "疑惑地看着$N。\n", me);
                return;
        }

        if( strsrch(msg, "chat") != -1 ||
            strsrch(msg, "sldh") != -1 ||
            strsrch(msg, "es") != -1 ||
            strsrch(msg, "rumor") != -1 ||  
            strsrch(msg, "xyj") != -1 ||  
            strsrch(msg, "tell") != -1 ||
            strsrch(msg, "follow") != -1 ||
            strsrch(msg, "apprentice") != -1 ||
            strsrch(msg, "recruit") != -1 )
                return;

        if (msg)
        {
                remove_call_out ("relaying");
                call_out ("relaying", 1+random(3), msg);
        }
}

void relaying (string msg)
{
        command (msg);
}

