//Cracked by Roath
// by happ@ys

#include <ansi.h>

inherit "/d/dntg/hell/wang.c";
//inherit NPC;
inherit F_MASTER;
int send_me();
int work_me();
string expell_me(object me);
string check_book();
int zhua_gui();
string ask_cancel();
string obstacle_sc();

void create()
{
       set_name("阎罗王", ({"yanluo wang","wang", "master", "yanluo"}));
       set("long", "身穿大红蟒袍，头戴黑绸软巾．
面如锅底，须若钢针，这就是阎罗王．\n");
       set("title", "阴间十王之");
        set("class", "youling");
       set("gender", "男性");
       set("age", 50);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
       set("max_kee", 1100);
       set("max_gin", 1100);
       set("max_sen", 1100);
       set("force", 1150);
       set("max_force", 1000);
       set("force_factor", 60);
       set("max_mana", 1500);
       set("mana", 1500);
       set("mana_factor", 50);
       set("combat_exp", 1000000);

        set_skill("jinghun-zhang", 150);
        set_skill("tonsillit", 100);
        set_skill("gouhunshu", 150);
       set_skill("unarmed", 150);
        set_skill("whip", 180);
        set_skill("sword", 150);
        set_skill("hellfire-whip",180);
        set_skill("zhuihun-sword", 150);
       set_skill("dodge", 120);
        set_skill("ghost-steps", 150);
       set_skill("parry", 150);
        set_skill("spells", 150);
        set_skill("force", 150);
        map_skill("sword", "zhuihun-sword");
        map_skill("parry", "zhuihun-sword");
        map_skill("dodge", "ghost-steps");
        map_skill("unarmed", "jinghun-zhang");
        map_skill("force", "tonsillit");
        map_skill("whip", "hellfire-whip");
        map_skill("spells", "gouhunshu");

        set("nk_gain", 500);

        set_temp("apply/armor", 50);
        set_temp("apply/dodge", 50);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "sheqi" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: cast_spell, "gouhun" :)
        }) );

set("inquiry", ([
"cancel" :(: ask_cancel :),
"还阳": (: expell_me :),
"leave": (: expell_me :),
"核对生死簿" : (: check_book :),
"watch":(:send_me:),
"十八层地狱":(: work_me :),
"18": (: work_me :),
"抓鬼" : (: zhua_gui :),
"灵台观礼": "哦，这个自由地藏王菩萨做主！\n",
"name": "哼！连老夫都不认得，想来是活的太久了！\n",
"here": "这便是阎罗地府，到阳间一谈，嘿嘿，没人不怕！\n",
"阳间": "人说阴阳殊途，其实不然，阴阳间有五点相交，来去相通！\n",
"五点": "哈哈，要说知道的人却也不多，那便是年，月，日，时和长安泾水桥！\n",
"刘父": (: obstacle_sc :),
"刘伯钦的父亲": (: obstacle_sc :),

]) );


create_family("阎罗地府", 2, "你好");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}
string obstacle_sc()
{
        object me = this_player();
        int i;
        if( me->query("obstacle/sc") == "done" )
        return("我不太清楚。\n");
                
        if( ! me->query_temp("can_ask") )
          return("我不太清楚。\n");

  i = random(600);
  me->add("obstacle/number",1);
  me->set("obstacle/sc","done");
    me->add("daoxing",i+8000);
  command("chat "+me->query("name")+"双叉坡灭虎，超度刘父灵魂显功劳！");
  me->save();
  return("你赢得了"+chinese_number(4)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");

}

void attempt_apprentice(object ob, object me)
{
        if ( (string)ob->query("family/family_name")=="阎罗地府") {
        if (((int)ob->query("combat_exp") < 50000 )) {
        command("say " + RANK_D->query_rude(ob) + "不掂掂斤两，老子没空教你！\n");
        return;
        }
        command("grin");
        message_vision("阎罗王对$N嘿嘿地笑了几声。\n", ob);
        message_vision("阎罗王拍拍$N的肩膀说道：以后在这里多用功，迟早有出头的日子！\n", ob);
       command("recruit " + ob->query("id") );
        return;
        }
        message_vision("阎罗王对$N喝道：你是那里来的毛贼，敢跑到宝殿上撒野！与我哄出去！\n", ob);
        message_vision("跑进来两个青面小鬼把$N拖了出去。\n", ob);
        ob->move("/d/diyu/walk7");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
}


int accept_fight(object me)
{
        command("say " + "哈哈！阎王不叫，自己上门！\n");
        return 1;
}
string expell_me(object me)
{       
        me=this_player();
        if((string)me->query("family/family_name")=="阎罗地府") {
                message_vision("阎罗王胡子抖抖，好像非常生气。\n", me);
                 me->set_temp("betray", "hell");
                message_vision("阎罗王对$N嚷嚷着：小东西，你说话是真心话(true)？\n", me);
                return ("气死我了，气死我了！\n");
        }
        return ("问什么问！自己想去！\n");
}
void init()
{
        add_action("do_true", "true");
        ::init();
}

int do_true(string arg)
{

        if(this_player()->query("family/family_name") != "阎罗地府" )
                return 0;
        if(this_player()->query_temp("betray")=="hell") {
                message_vision("$N答道：弟子讲的真心话！\n\n", this_player());
                message_vision("阎罗王叹了口气，既是如此，你便还阳去吧！\n", this_player());
this_player()->set("combat_exp",this_player()->query("combat_exp")/5*4);
this_player()->set("daoxing",this_player()->query("daoxing")/5*4);
                this_player()->add("betray/count", 1);
                this_player()->add("betray/hell", 1);
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                 this_player()->set("faith",0);
                this_player()->set_temp("betray", 0);
                this_player()->save();
                message_vision("阎罗王伸出手将$N一推，$N化作一股青烟向东而去。。。\n", this_player());
                this_player()->move("/obj/void");
                tell_room( environment(this_player()),"房梁上噗噗嗦嗦几声响，掉下个人来！\n", ({this_player()}));
                this_player()->unconcious();            
                return 1;
                }
        return 0;
}

int zhua_gui()
{
        object ghost;
        object me = this_player();
        string* dirs;

        dirs = ({"/d/4world/","/d/city/","/d/gao/", "/d/jjf/",
"/d/lingtai/", "/d/meishan/","/d/moon/", "/d/nanhai/", "/d/penglai/",
"/d/sea/", "/d/xueshan/", "/d/qujing/nuerguo/",
"/d/qujing/wudidong/", "/d/qujing/firemount/"});

        seteuid(getuid());

        if( (string)me->query("family/family_name")!="阎罗地府" ) {
                message_vision("$N斜斜的瞥了$n一眼，冷笑道：就你，好笑好笑。。。\n", this_object(), me);
                return 1;
                }
        if( time() - me->query("last_time/zhuagui") < 120 )
                {
                command("say 有劳了,你先去休息休息吧\n");
                return 1;
                }
if( me->query("faith") > 800|| me->query("combat_exp") > 500000 )
                {
                command("say 不敢劳您大驾！\n");
                return 1;
                }                
            if( ! me->query("Hell_Job/done")&& me->query("Hell_Job/time_start") )
                {
                command("say 这点事情都办不好，真是个饭桶，过会再来吧。\n");
            call_out("cancel",120 ,me);
                return 1;
                }

        ghost = new("/obj/npc/ghost");
        ghost->move("/obj/void");
        ghost->invocation(me, dirs);
        command("consider"); 
        command("say 据崔判官说，跑了个牢中恶鬼，大概在附近，使用 cast xungui和 cast yinyang 把他抓回来.\n");
        me->set("Hell_Job/time_start", time());
        me->delete("Hell_Job/done");
        me->set("last_time/zhuagui",time());
        return 1;
}
void cancel(object me)
{
        me->set("Hell_Job/done",1);
}

int send_me()
{
        object who;
        who=this_player();
        message_vision("$N对$n点了点头，道：是你自己要去，回不来别怨我。\n",this_object(),who);
        who->move("/d/death/emptyroom");
        return 1;
}
int work_me()
{
        object who;
        who=this_player();

        if( (int)who->query("combat_exp") < 300000 ) {
                message_vision("$N对$n一拱手，道：道行不够，强求亦是枉然。\n", this_object(),who);
                return 1;
        }
        if( who->query("HellZhenPass") && who->query("fangcun/panlong_hell_18")!="begin") {

message_vision("$N对$n一拱手，道：即是武功高强，我等佩服便是，这。。。便是免了吧！\n",this_object(),who);
        return 1;
        }
        if( this_object()->query_temp("SomeonePassing") ) {
                message_vision("$N对$n一拱手，道：真时机缘不巧，改日再来吧。\n",this_object(),who);
                return 1;
        }


message_vision("$N对$n阴阴地笑了几声，说：天堂有路你不走，地狱无门你闯进来。\n",this_object(),who);
        this_object()->set_temp("SomeonePassing");
//add a chat here.
        command("chat "+who->query("name")+"要闯俺地府十八层地狱，哼！等着收尸吧！\n");

        message_vision("$N双手拍了一下，$n脚下突然陷了下去。。。\n", this_object(),who);
        who->delete("env/brief_message");
        who->move("/d/death/emptyroom");

        command("grin");
        this_object()->move("/obj/void");
        
//      call_out("get_all",1,who);
        call_out("message",3,who);
        call_out("round_1",4, who);
        return 1;
}
/*
int get_all(object who)
{
  object me = this_object();
  object *obs = all_inventory (who);
  int i = sizeof(obs);

  message_vision ("一阵狂风吹来，佛爷出现！\n",who);
  while (i--)
  {
    object ob = obs[i];

    if (ob == me)
      continue;
    if (ob->query("no_get"))
      continue;
    if (ob->query("no_drop"))
      continue;

    message_vision ("佛爷从$N身上搜出$n！\n",who,ob);
    if (! interactive(ob))
      destruct (ob);
    else
      ob->move(environment(who));
  }  
    return 1;
}
*/
int check_status(object who)
{
        if( (int)who->query("kee") < 50 
        ||      (int)who->query("eff_kee") < 50 ) {
                remove_call_out("round_2");
                remove_call_out("round_3");
                remove_call_out("round_4");
                remove_call_out("round_5");
                remove_call_out("round_6");
                remove_call_out("round_7");
                remove_call_out("round_8");
                remove_call_out("round_9");
                remove_call_out("round_10");
                remove_call_out("round_11");
                remove_call_out("round_12");
                remove_call_out("round_13");
                remove_call_out("round_14");
                remove_call_out("round_15");
                remove_call_out("round_16");
                remove_call_out("round_17");
                remove_call_out("round_18");
                remove_call_out("message");
                remove_call_out("winning");
                call_out("failed",1,who);
                return 1;
        }
}
int failed(object who)
{       
        command("chat* 阎罗王狂笑了几声。");
        command("chat 果真有不怕死的，可惜还是逃不出俺的手掌心！\n");
        this_object()->delete_temp("SomeonePassing");
        who->move("obj/void");
        who->unconcious();
        this_object()->move("/d/death/zhengtang");
        call_out("remove_all", 3);
        return 1;
}
int remove_all()
{       int i;
        object *list,empty;

        if( !(empty = find_object("/d/death/emptyroom")) )
                empty = load_object("/d/death/emptyroom");
        write("四周刮起一阵阴风。。。\n");
        if( empty = find_object("/d/death/emptyroom") ) {

                list=all_inventory(empty);
                i = sizeof(list);
                while (i--)
                {
                        object ob=list[i];
                        ob->move("/d/changan/fendui");
                }
        }
        return 1;
}

int winning(object who)
{
     if (who->query("fangcun/panlong_hell_18")=="begin")
      {
        command("chat "+who->query("name")+"，竟然闯过了我幽冥地府十八层地狱！\n");
		who->set("fangcun/panlong_hell_18","done");
        this_object()->move("/d/death/zhengtang");
        this_object()->delete_temp("SomeonePassing");
        call_out("remove_all", 3);
        return 1;
      }
// add a chat here.
        command("chat "+who->query("name")+"，算你走运，下回可没这么便宜了！\n");
// add reward here.
        who->add("kar", 10);
        who->add("potential", 1000);
        who->add("daoxing", 5000);
        tell_object(who,"你得到了一千点潜能和五年道行。\n");
        who->set("HellZhenPass",1);
        this_object()->move("/d/death/zhengtang");
        this_object()->delete_temp("SomeonePassing");
        call_out("remove_all", 3);
        return 1;
}
int message(object who)
{
        switch(random(5)) {

                case 0:
tell_room(environment(who),"\n你觉得自己不断下降，周围景物如彩蝶翻飞，不可注目。\n");
break;
                case 1:
tell_room(environment(who),"\n你觉得自己不断下降。\n");
break;
                case 2:
tell_room(environment(who),"\n你觉得自己不断下降，天地似乎没了界限。。。\n");
break;
                case 3:
tell_room(environment(who),"\n你觉得自己不断下降，周围一切都在旋转。。。\n");
break;
                case 4:
tell_room(environment(who),"\n你觉得自己不断下降，下降，似乎落向了无尽的深渊。\n");
break;
        }
        return 1;
}
int round_1(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/1");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),RED"                **************************************\n"NOR);
        tell_room(environment(who),RED"                **               吊筋狱             **\n"NOR);
        tell_room(environment(who),RED"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_2", 3, who);
        return 1;
}

int round_2(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/2");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        tell_room(environment(who),GRN"                **               幽枉狱             **\n"NOR);
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_3", 3, who);
        return 1;
}
int round_3(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/3");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        tell_room(environment(who),YEL"                **               火坊狱             **\n"NOR);
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_4", 3, who);  
        return 1;
}
int round_4(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/4");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        tell_room(environment(who),BLU"                **               酆都狱             **\n"NOR);
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_5", 3, who);  
        return 1;
}
int round_5(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/5");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),MAG"                **************************************\n"NOR);
        tell_room(environment(who),MAG"                **               拔舌狱             **\n"NOR);
        tell_room(environment(who),MAG"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_6", 3, who);  
        return 1;
}
int round_6(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/6");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        tell_room(environment(who),CYN"                **               剥皮狱             **\n"NOR);
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_7", 3, who);  
        return 1;
}
int round_7(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/7");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIR"                **************************************\n"NOR);
        tell_room(environment(who),HIR"                **               磨涯狱             **\n"NOR);
        tell_room(environment(who),HIR"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_8", 3, who);  
        return 1;
}
int round_8(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/8");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIG"                **************************************\n"NOR);
        tell_room(environment(who),HIG"                **               锥捣狱             **\n"NOR);
        tell_room(environment(who),HIG"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_9", 3, who);  
        return 1;
}
int round_9(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/9");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIY"                **************************************\n"NOR);
        tell_room(environment(who),HIY"                **               车崩狱             **\n"NOR);
        tell_room(environment(who),HIY"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_10", 3, who);  
        return 1;
}
int round_10(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/10");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIB"                **************************************\n"NOR);
        tell_room(environment(who),HIB"                **               寒冰狱             **\n"NOR);
        tell_room(environment(who),HIB"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_11", 3, who);  
        return 1;
}
int round_11(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/15");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/11");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIM"                **************************************\n"NOR);
        tell_room(environment(who),HIM"                **               脱壳狱             **\n"NOR);
        tell_room(environment(who),HIM"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_12", 3, who);  
        return 1;
}
int round_12(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/11");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/12");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIC"                **************************************\n"NOR);
        tell_room(environment(who),HIC"                **               抽肠狱             **\n"NOR);
        tell_room(environment(who),HIC"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_13", 3, who);  
        return 1;
}
int round_13(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/16");

        seteuid(getuid());
        ghost=new("/d/death/HellZhen/13");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),HIW"                **************************************\n"NOR);
        tell_room(environment(who),HIW"                **               油锅狱             **\n"NOR);
        tell_room(environment(who),HIW"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_14", 3, who);  
        return 1;
}
int round_14(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/18");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/14");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),RED"                **************************************\n"NOR);
        tell_room(environment(who),RED"                **               黑暗狱             **\n"NOR);
        tell_room(environment(who),RED"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_15", 3, who);  
        return 1;
}
int round_15(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/15");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        tell_room(environment(who),GRN"                **               刀山狱             **\n"NOR);
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_16", 3, who);  
        return 1;
}
int round_16(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/15");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/16");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        tell_room(environment(who),YEL"                **               血池狱             **\n"NOR);
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_17", 3, who);  
        return 1;
}
int round_17(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/16");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/17");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        tell_room(environment(who),BLU"                **               阿鼻狱             **\n"NOR);
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_18", 3, who);  
        return 1;
}
int round_18(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/18");
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/17");
        tell_room(environment(who),"\n突然间一道黑牌闪过：\n\n");
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        tell_room(environment(who),CYN"                **               秤杆狱             **\n"NOR);
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("winning", 3, who);  
        return 1;
}
string check_book()
{
        object me=this_player();

    if(me->query("family/family_name")!="阎罗地府")
      return ("你不是本门中人！");
   if(me->query("faith")>200)
      return ("你现在的身份已不用查生死簿了。"); 
      if(me->is_busy())
      return ("你正忙着呢！");

   command("say 这儿有一卷生死簿可能有误，你去替我核对一下。");
    message_vision("$N在桌子旁坐下，聚精会神地进行核对。\n",me);
   me->start_busy(5);
   call_out("finish_check_book",5,me,this_object());
   command("nod");
   return ("果然是一个勤快人。");
}

void finish_check_book(object me,object master)
{
    message_vision("$N查了许久，终于将一卷生死簿查完了，松了一口气，只觉得双眼发酸！\n");
    me->receive_damage("sen",20);
    message_vision("$N走到阎罗王面前，恭恭敬敬地说了声：禀告王爷，查完了，没错！\n",me);
    command("pat "+me->query("id"));
    command("say 好弟子！");
    tell_object(me,"你觉得对勾魂术有了一些领悟。\n");
    me->add("faith",1);
    me->add("combat_exp",9);
    me->add("potential",3);
    me->improve_skill("gouhunshu",random(me->query("int")),1);  
}
