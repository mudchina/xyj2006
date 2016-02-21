// by snowcat oct 24 1997

inherit NPC;

void create()
{
  set_name("金钗女", ({"jinchai nu", "nu", "girl"}) );
  set("gender", "女性" );
  set("age", 20);
  set("long","一位柳眉粉面含笑，蛾裙领露酥胸的美女。\n");

  set("combat_exp", 2500);
  set("str", 15);
  set("attitude","heroism");

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init()
{
  remove_call_out ("says");
  if(userp(this_player())) {
  add_action ("do_sleep","sleep");
  call_out("says",random(3),this_object());
  }
}

void says (object me)
{
  string *msgs = ({
    "$N吃吃一笑，抿嘴看着你。\n",
    "$N含情脉脉地对你说……我……\n",
    "看来$N很想跟你……如果你愿意，也请下一次 sleep 命令。\n",
    "$N冲着你会心地一笑，点了点头。\n",
    "$N很想跟你……\n",
    "$N对你婉尔一笑。\n",
  });
  message_vision (msgs[random(sizeof(msgs))],me);
  remove_call_out ("says");
  if(sizeof(filter_array(all_inventory(environment(this_object())), (:userp:))))
  call_out("says",random(40),me);
}

int do_sleep ()
{
  object me = this_object();
  object who = this_player();
  message_vision ("$N搂着$n柔软的身体，不由得心醉神迷……\n\n",who,me);
  who->command_function("remove all");
  who->start_busy(3,3);
  remove_call_out ("get_fainted");
  call_out ("get_fainted",1,who,me);
  remove_call_out ("says");
  call_out("says",40,me);
  return 1;
}

void get_fainted (object who, object me)
{
  object *objs = all_inventory(who);
  int i = sizeof (objs);
  message_vision ("$N对$n神秘地一笑。\n\n",me,who);
  who->unconcious();    
  while (i--)
  {
    object obj = objs[i];
    message_vision ("$N从$n身上拿出"+obj->query("name")+"。\n",me,who);
    obj->move(me);
    destruct(obj);
  }
}
int accept_object(object me, object ob)
  {
        object lw;
        lw=new("/u/mind/lwbook.c");
        
//if((string)ob->query("name")=="催情秘药" )
if((string)ob->query("id")=="cuiqing miyao" )
        {
         command("smile");
         command("say 这位" + RANK_D->query_respect(me) +"真是有心人，我就赠一礼物予你。");
        call_out("destroy", 1, ob);
	lw->move(me);
	 me->save();
        
        return 1;       
        }
 }
void destroy(object ob)
{
        destruct(ob);
        return;
}
