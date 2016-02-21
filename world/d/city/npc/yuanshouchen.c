inherit NPC;
inherit F_MASTER;
string suanming(object me);
string suan_fuyuan(object me);
string suan_rsg(object me);
string ask_mieyao();
string ask_cancel();

string ask_sihou();
 int longwang();
void create()
{
        set_name("袁守诚", ({"yuan shoucheng","yuan"}));
        set("title","算命先生");
        set("gender", "男性" );
        set("age", 55);
        set("class","taoist");
        set("long", "能知天地理，善晓鬼神情．长安城里没有不认识他的。\n");
        set("combat_exp", 800000000);
        set("daoxing", 80000000);

        set("attitude", "peaceful");
        set_skill("unarmed", 10);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("literate", 50);
        set_skill("spells", 50);
        set_skill("mysticism", 50);
set_skill("whip", 150);
        set_skill("wuwei-fuchen", 180);
        set_skill("binfen-steps", 50);
        
        set("per", 15);
   set("max_kee", 350000);
        set("max_gin", 300000);
        set("max_sen", 300000);
        set("max_mana", 200000);
        set("mana", 200000);
        set("mana_factor", 1000);
        create_family("三界散仙", 1, " 白");
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("inquiry", ([
                "name" : "小道姓袁名守诚．．．嘿嘿，在这长安一带还算小有薄名。\n",
                "here" : "你没来过长安？这地方可是天下第一繁华所在。\n", 
            "人参果" : (: suan_rsg :),
            "rsg" : (: suan_rsg :),
            "福缘" : (: suan_fuyuan :),
        "fuyuan" : (: suan_fuyuan :),
            "算命" : (: suanming :),
            "算卦" : (: suanming :),
            "suanming" : (: suanming :),
"混世四猴" : (: ask_sihou :),
 "泾河龙王" : (: longwang :),
// "灭妖": (: ask_mieyao :),
           "cancel": (: ask_cancel :),
         ]) );

        set("chat_msg", ({
            "袁守诚晃了晃手上的桂花酒袋笑道：我这人没别的毛病，就是好点这个。\n",       
                "袁守诚上上下下打量了你几眼。\n",
                "袁守诚皱了皱眉，一副欲言又止的样子。\n",
                "袁守诚神秘兮兮地四面张望了一下，在你耳边悄声道：\n客官最近没觉得哪儿不得劲？\n",
        }) );
}
string suan_fuyuan(object me)
{
       int my_level;

       string *levels = ({
         "霉气冲天，恕在下直言，血光之灾不远矣！\n",
         "印堂发暗，这个这个．．．\n",
         "运道尚可。\n",
         "今生福缘不浅呀！。\n",
         "定是多福多寿之人。\n",
         "今生必有奇缘，恭喜，恭喜！\n",
         "真是福如东海，寿比南山呀！\n",
          });

        me = this_player();

my_level=(me->query("gift_modify/kar")+me->query("kar")+me->query("donation")/1000000)/5-2;
        if(my_level>6 ) my_level=6;
        if( !me->query_temp("suanming/paid") )
        {
                if( me->query_temp("suanming/asked") ) 
                {
                        message_vision("袁守诚闭上眼睛，不理$N了。\n", me);
                        return "在下正需一条金色鲤鱼，不知"
                          +RANK_D->query_respect(me)+"能否搞来。\n";
                }
                else
                {
                        me->set_temp("suanming/asked", 1);
                        message_vision("袁守诚拖长声音干咳了几声。\n", me);
                        return "这个．．．天机不可泄露啊。\n";
                }
        }
        else
        {
                me->delete_temp("suanming");
                message_vision("袁守诚对$N道：你算是找对人了！说罢掐指算了几算。\n", me);
                if(my_level<0 )
                        return "奇怪！"+RANK_D->query_respect(me)+
                            "运数十分怪异，在下修为不够，算不出来．．．\n";
                else
                   return RANK_D->query_respect(me)+levels[my_level];
        }
}
string ask_mieyao()
{
    object who=this_player();

    if((string)who->query("family/family_name")=="三界散仙") {
      command("smile "+who->query("id"));
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("非我门人,何故来此?\n");
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}


string suan_rsg(object me)
{
        me = this_player();

        if( !me->query_temp("suanming/paid") )
        {
                if( me->query_temp("suanming/asked") ) 
                {
                        message_vision("袁守诚闭上眼睛，不理$N了。\n", me);
                        return "在下正需一条金色鲤鱼，不知"
                          +RANK_D->query_respect(me)+"能否搞来。\n";
                }
                else
                {
                        me->set_temp("suanming/asked", 1);
                        message_vision("袁守诚拖长声音干咳了几声。\n", me);
                        return "这个．．．天机不可泄露啊。\n";
                }
        }
        else
        {
                me->delete_temp("suanming");
                if(me->query("rsg_eaten")<=0)
                    return RANK_D->query_respect(me)+
                        "还没尝过人参果的滋味了吧？";
                else
                message_vision("袁守诚对$N道：你算是找对人了！说罢掐指算了几算。\n", me);
                   return "听说"+RANK_D->query_respect(me)+"已经吃了"+
                       chinese_number(me->query("rsg_eaten"))+"颗人参果，真是福缘不浅呀！\n";
        }
}


string suanming(object me)
{
        me = this_player();

        if( !me->query_temp("suanming/paid") )
        {
                if( me->query_temp("suanming/asked") ) 
                {
                        message_vision("袁守诚闭上眼睛，不理$N了。\n", me);
                        return "在下正需一条金色鲤鱼，不知"
                          +RANK_D->query_respect(me)+"能否搞来。\n";
                }
                else
                {
                        me->set_temp("suanming/asked", 1);
                        message_vision("袁守诚拖长声音干咳了几声。\n", me);
                        return "这个．．．天机不可泄露啊。\n";
                }
        }
        else
        {
                me->delete_temp("suanming");
                message_vision("袁守诚对$N道：你算是找对人了！说罢掐指算了几算。\n", me);
                if(me->query("life/live_forever"))
                        return "失敬！失敬！原来"+
                            RANK_D->query_respect(me)+
                            "跳出三界外，不在五行中，已是戡破生死大限了！\n";
                else if(me->query("age")<16)
                    return RANK_D->query_respect(me)+
                        "定会长命百岁，前途不可限量！\n";
                else
                   return RANK_D->query_respect(me)+"有"+
                       chinese_number(me->query("life/life_time"))+"年的阳寿。\n";
        }
}
int accept_object(object me, object ob)
{
        object nowords;
        
        if(userp(ob)) return 0;

        if( (string)ob->query("name")=="桂花酒袋" )
        {
                command("u&me " + me->query("id"));
                command("say 这位" + RANK_D->query_respect(me) + "就是跟我投缘！\n这里我也有一点小意思，请笑纳。\n");
                carry_object("/d/obj/book/nowords");
                command("give nowords to " + me->query("id"));
                return 1;
        }
        else if( (string)ob->query("name")=="金色鲤鱼" 
                 && (string)ob->query("id")=="fish" )
        {
                message_vision("袁守诚满面堆欢地对$N道：多谢"+RANK_D->query_respect(me)+"，在下正需要这个，有什么问题您尽管问！\n", me);
                me->set_temp("suanming/paid", 1);
                return 1;
        }
        else
        {
            command("say 不敢当不敢当．．．您太客气了。");
            return 1;
        }
}


// add by mind
void attempt_apprentice(object me)
{
        
if((string)me->query("family/family_name")=="三界散仙")
    {
      command("recruit " + me->query("id"));
        me->set("class", "sanxian");
        me->set("title","三界散仙 相士");
    }
        call_out("do_recruit", 2, me);
        command("say 我只会几招三脚猫的功夫。。。\n",);
                             
        
}

void do_recruit(object ob)
{
          if((int) ob->query_temp("wait_time") < 360)
        
        {
          command("say 在下不敢误人子弟啊．．．\n");
        return;
        }
        if((int)ob->query("water") > 0 || (int)ob->query("food") > 0)
        {
          command("say 在下不敢误人子弟啊．．．\n");
        return;
        }
          if(ob->query("daoxing") > 50000 || ob->query("combat_exp") > 50000)
        {
          command("say 在下不敢误人子弟啊．．．\n");
        return;
        }
        else {

                command("sigh");
                command("say 如此心诚，在下就传你玄玄神机！日后切勿妄泄天机。");
                command("recruit " + ob->query("id") );
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "sanxian");
                ob->set("title", "三界散仙 相士");
}
string ask_sihou()
{
        object who,me,room;
        
        who = this_player();
        me = this_object();
if ( who->query("family/family_name") == "三界散仙"){
        command("sigh " + who->query("id"));
        command("say " + "天地之间共有十类之种，五仙：天、地、神、人、鬼。
        五虫：嬴、鳞、毛、羽、昆。而混世四猴却不入此十类之中。灵明石猴，就
        是那大闹天宫的孙行者，六耳猕猴现出没在花果山附近。通臂猿猴能拿日月、
        缩千山，辨休咎，乾坤摩弄，至于晓阴阳、会人事、善出入、避死延生的赤
        臀马猴曾投胎凡间，因孙大圣阎王生死簿涂抹了猴族数百种，这两位辗转于
        轮回之外，难以重生，乃鬼气也！\n");
        command("say " + "那通臂猿猴几百年前乃世间百家争鸣之时一个明家祖师。
        你欲见他，恐不容易，但我送你一程，却也不妨。\n");
        if(!( room = find_object("/d/sanxian/caodi")) )
            room = load_object("/d/sanxian/caodi");
        if(objectp(room))
            who->move(room);
        return "\n袁守诚伸手一拍你的后心，咄地轻喝一声，疾！。\n\n";
}
}
int longwang()
{
  object me;
   me=this_player();
 if (me->query_temp("fangcun/panlong_longgong_yuanshoucheng")!="begin")
 return 0;
command("sigh");
command("say 这位" + RANK_D->query_respect(me) + "只知其一不知其二，小道在长安以算命为生，前几日为一渔夫张稍算
    他何时何处下网均是百下百中．谁知惹恼了那泾河龙王，一日他化作一秀士卜天上阴晴;
    事，小道如实告知，那龙王为逞淫威违了玉帝旨意，改了时辰，克了尺寸．反而找小道;
    麻烦，说是算卦不准要赶小道出长安城，无奈小道只好识破他龙王真面目，且指点那泾;
    河龙王去求当朝吾皇太宗与他到丞相魏征处讨个人情，太宗皇帝为救那泾河龙王于当日;
    巳末午初之际命人招魏征入金銮宝殿对弈一局，谁知午时三刻一到那魏征残局未终，伏;
    案便睡，梦离金銮殿，剐龙台斩了泾河龙王．" + RANK_D->query_respect(me) + "如若不信可去问过当日传旨泾河龙;
      王降雨的仙将‘泾河龙王’一事\n");
   me->set_temp("longwang_yuan",1);
return 1;
}
