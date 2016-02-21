inherit NPC;

string say_position();
void create()
{
       set_name("ÍòÊ¥¹«Ö÷", ({"wansheng gongzhu","gongzhu","princess"}));

        set("long","ÍòÊ¥¹«Ö÷ÊÇÍòÊ¥ÁúÍõµÄÅ®¶ù£¬×î½üÕÐÁË¾ÅÍ·¹ÖÎªæâÂí¡£\n");
       set("gender", "Å®ÐÔ");
       set("age", 20);
        set("int", 25+random(5));
       set("attitude", "peaceful");
        set("combat_exp", 280000);
  set("daoxing", 300000);

	set("eff_dx", -100000);
	set("nkgain", 400);
       set("rank_info/respect", "¹«Ö÷µîÏÂ");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 800);
       set("max_sen", 500);
       set("force", 800);
       set("max_force", 600);
       set("force_factor", 20);
       set("max_mana", 500);
       set("mana", 400);
       set("mana_factor", 10);
       set_skill("literate", 70);
	set_skill("stealing", 70);
       set_skill("unarmed", 70);
       set_skill("dodge", 160);
       set_skill("force", 70);
       set_skill("parry", 70);
       set_skill("spells", 70);
        set_skill("dragonfight", 70);
        set_skill("dragonforce", 70);
        set_skill("dragonstep", 70);
        map_skill("unarmed", "dragonfight");
        map_skill("force", "dragonforce");
        map_skill("dodge", "dragonstep");
	set("inquiry",([
		  "±¦±´": "Ê²Ã´±¦±´²»±¦±´µÄ£¡\n",
		  "·ð±¦": "·ð±¦ÏÖÊÇÎÒÁú¹¬µÄÕòÌ¶Ö®±¦ÁË£¬Ë­Ò²ÄÃ²»µ½¡£\n",
                  "·½Î»": (: say_position :),
                  ]));

        setup();
	carry_object("/d/qujing/bibotan/obj/clasp")->wear();
        carry_object("/d/obj/cloth/pinkskirt")->wear();
}


int recognize_apprentice(object who)
{	who= this_player();
	if( who->query("family/family_name")=="ÂÒÊ¯É½±Ì²¨Ì¶" 
		&& who->query("can_learn_stealing") ) { 
        	return 1;
	}
	return 0;
}

string say_position()
{	object me =this_object();
	object who=this_player();

	if( me->is_fighting() || who->is_fighting() )
	return ("Ê²Ã´·½Î»²»·½Î»µÄ£¬ÎÒ²»¶®¡£\n");

	if(member_array("tianboer xiao", who->parse_command_id_list())==-1) {
		call_out("kill_him", 1, who);
		return ("½ñÈÕ²»³ýÄã£¬ÖÕ³ÉÎÒÁú¹¬´ó»¼£¡\n");
	}

	if( me->query("talked") )
	return ("Ê²Ã´·½Î»²»·½Î»µÄ£¬ÎÒ²»ÊÇÒÑ¾­¸æËßÄã£¡\n");
	me->set("talked", 1);
	call_out("tell_position", 1, who);
	return "";
}
void tell_position(object who)
{
	if( !who || environment(who) != environment()) return;
	switch (random(8)) {
		case 0:
			command("whisper xiao ½ñÈÕ·½Î»ÔÚÇ¬Î»¡£");
			who->set_temp("heard_position", "Ç¬");
		break;
                case 1:
                        command("whisper xiao ½ñÈÕ·½Î»ÔÚÀ¤Î»¡£");
                        who->set_temp("heard_position", "À¤");
                break;
                case 2:
                        command("whisper xiao ½ñÈÕ·½Î»ÔÚ¶ÒÎ»¡£");
                        who->set_temp("heard_position", "¶Ò");
                break;
                case 3:
                        command("whisper xiao ½ñÈÕ·½Î»ÔÚÀëÎ»¡£");
                        who->set_temp("heard_position", "Àë");
                break;
                case 4:
                        command("whisper xiao ½ñÈÕ·½Î»ÔÚÕðÎ»¡£");
                        who->set_temp("heard_position", "Õð");
                break;
                case 5:
                        command("whisper xiao ½ñÈÕ·½Î»ÔÚôÞÎ»¡£");
                        who->set_temp("heard_position", "ôÞ");
                break;
                case 6:
                        command("whisper xiao ½ñÈÕ·½Î»ÔÚÙãÎ»¡£");
                        who->set_temp("heard_position", "Ùã");
                break;
                case 7:
                        command("whisper xiao ½ñÈÕ·½Î»ÔÚ¿²Î»¡£");
                        who->set_temp("heard_position", "¿²");
                break;
	}
}
void kill_him(object who)
{
	object husband = present("jiutou fuma", environment(this_object()));
	
	if(husband)
	husband->kill_ob(who);
	::kill_ob(who);
}

void die()
{
    object me,who,longjin;
    string whoid;
    me=this_object();
    if(me->query_temp("longjin_kill"))
	{
		  whoid=me->query_temp("longjin_kill");
    	  if (!present(whoid,environment()))
        	  return ::die();
	  	  who=present(whoid,environment());
          if((who->query("fangcun/panlong_hell_18")=="done")&&(who->query("fangcun/panlong_hell_longjin")=="begin")&&(environment()))
		{
			  longjin=new("/d/sea/obj/longjin");
			  longjin->set_temp("iambaddragon",1);
			  longjin->move(me);
			  ::die();
			  return; 
		}
	}
    ::die();
}

ÿ