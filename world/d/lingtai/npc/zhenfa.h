
#include <ansi.h>

string* names = ({
        "guang jingzi",
        "guang guanzi",
        "guang mingzi",
        "guang zhizi",
        "guang hezi",
        "guang jizi",
        "guang wenzi",
        "guang xinzi",
});

string* saywords=({
        "一住行窝几十年，",
        "蓬头长日走如颠。",
        "海棠亭下重阳子，",
        "莲叶舟中太乙仙。",
        "无物可离虚壳外，",
        "有人能悟未生前。",
        "出门一笑无拘碍，",
        "云在西湖月在天！",
        });
        
mapping oldexits;

string ask_sixiang()
{
        mapping skl; 
        object fighter, me ;
        string *sname;
        int i,j;

        fighter = this_player();
        me = this_object();

        skl = fighter->query_skills();
        if (sizeof(skl) <= 1)
                return RANK_D->query_respect(fighter) + 
                "功力不够，不够资格闯四象阵。";
        sname  = keys(skl);
        for(i=0; i<sizeof(skl); i++) {
                if ((skl[sname[i]] < 100) || (sizeof(skl) == 0))
                return RANK_D->query_respect(fighter) + 
                "功力不够，不够资格闯四象阵。";
        }
        if( fighter->query("sixiang_winner") )
                return RANK_D->query_respect(fighter) + 
                "已然闯过四象阵，可不要开这等玩笑。";

        if( fighter->query("family/family_name")!="方寸山三星洞")
                return RANK_D->query_respect(fighter) + "不是本门中人，闯什么四象阵。";

        if ( me->query("assigned_sixiang")||me->query("assigned_bagua") )
                return RANK_D->query_respect(fighter) + 
                "，今日已有人闯阵，你过一段时间再来吧。";

        command("say 好吧，就随我到上面空地上闯阵吧！");

        me->set("assigned_sixiang", fighter->query("id"));              
        message_vision("\n云阳真人飘然向上离开。\n", fighter);
        me->move("/d/lingtai/wuchang");
        tell_room(environment(me),"云阳真人说道：大家准备好了，有人闯阵！\n");

        call_out("waiting", 1, me);

        return "好！大家都出来了。\n";
}

string ask_bagua()
{
        mapping skl; 
        object fighter, me ;
        string *sname;
        int i,j;

        fighter = this_player();
        me = this_object();

        skl = fighter->query_skills();
        if (sizeof(skl) <= 1)
                return RANK_D->query_respect(fighter) + 
                "功力不够，不够资格闯八卦阵。";
        sname  = keys(skl);
        for(i=0; i<sizeof(skl); i++) {
                if ((skl[sname[i]] < 100) || (sizeof(skl) == 0))
                return RANK_D->query_respect(fighter) + 
                "功力不够，不够资格闯八卦阵。";
        }
        if( fighter->query("bagua_winner") )
                return RANK_D->query_respect(fighter) + 
                "已然闯过八卦阵，可不要开这等玩笑。";

        if( fighter->query("family/family_name")!="方寸山三星洞")
                return RANK_D->query_respect(fighter) + "不是本门中人，闯什么八卦阵。";

        if ( me->query("assigned_sixiang")||me->query("assigned_bagua") )
                return RANK_D->query_respect(fighter) + 
                "，今日已有人闯阵，你过一段时间再来吧。";

        command("say 好吧，就随我到上面空地上闯阵吧！");

        me->set("assigned_bagua", fighter->query("id"));                
        message_vision("\n云阳真人飘然向上离开。\n", fighter);
        me->move("/d/lingtai/wuchang");
        tell_room(environment(me),"云阳真人说道：大家准备好了，有人闯阵！\n");

        call_out("waiting", 1, me);

        return "好！大家都出来了。\n";
}

int waiting(object me)
{
        object fighter;
        int wait_time;

        if( wait_time == 300 )
        {
                say( "云阳真人说道：看来他不会来了，真是没用的东西！\n\n");
                call_out("do_back", 0, me);             
        }

        if((me->query("assigned_sixiang")&&!objectp(fighter=present( me->query("assigned_sixiang"), environment(me))))||
            (me->query("assigned_bagua")&&!objectp(fighter=present( me->query("assigned_bagua"), environment(me)))))
        {
                wait_time++;
                call_out("waiting", 1, me);
        }
        else    call_out("preparing", 1, me, fighter);

        return 1;
}

int preparing(object me, object fighter)
{
        object room;
        string zhname;

        if(!( room = find_object("/d/lingtai/wuchang")) )
        room = load_object("/d/lingtai/wuchang");
        
        if(me->query("assigned_sixiang")){
            zhname="四象阵";
            message("vision", HIY "\n云阳真人大声宣布：四象阵合围！\n" NOR, room);
            message("vision", "\n只听四周响起沙沙的脚步声，四位真人神情肃杀，\n"
                "手持木杖，分成四方慢慢地围了上来，堵住了通路。\n\n", room);
        }else{
            zhname="八卦阵";    
            message("vision", HIY "\n云阳真人大声宣布：八卦阵合围！\n" NOR, room);
            message("vision", "\n只听四周响起沙沙的脚步声，八位真人神情肃杀，\n"
                "手持木杖，站住八个方位，堵住了通路。\n\n", room);
        }
        oldexits=room->query("exits");
        room->delete("exits");

        say( HIY"云阳真人又道：准备，"+zhname+"即刻发动！\n\n"NOR);

        fighter->delete_temp("beat_count");
        fighter->set_temp("fighting", 1);

        if(me->query("assigned_sixiang"))call_out("fighting",  5, me, fighter, 0);
        else call_out("bfighting",  5, me, fighter, 0);

        return 1;
}

int fighting(object me, object fighter, int count)
{
        object daoshi1, daoshi2, room1, room2;

        if(!( room1 = find_object("/d/lingtai/xiuwu")) )
        room1 = load_object("/d/lingtai/xiuwu");

        if(!( room2 = find_object("/d/lingtai/wuchang")) )
        room2 = load_object("/d/lingtai/wuchang");

        if( count <4 ) {
                message("vision", HIW"\n四人迅速游走，只见两人双双抢出，\n" NOR, room2);

                daoshi1 = present(names[count*2%4], room1);
                daoshi1->move(room2);
                daoshi2 = present(names[count*2%4+1], room1);
                daoshi2->move(room2);

                message("vision", HIW+daoshi1->query("name")+"和"
                   +daoshi2->query("name")+"两人各出一招后迅速退回原位！\n" NOR, room2);
                daoshi1->move(room1);
                daoshi2->move(room1);
        }

        if( !find_player(me->query("assigned_sixiang")) ||
        !living(fighter) || fighter->query("kee") <= 1 )
        {
                if( objectp(present(me->query("assigned_sixiang"), environment(me)) )) {
                        fighter->delete_temp("fighting");
                        fighter->delete_temp("beat_count");
                }

                say( "云阳真人摇了摇头，说道：想不到 ... 唉！\n\n");
                command("sigh");
                call_out("do_back", 5, me );
        }
        else if( count >= 3 )
        {
                if( (int)fighter->query_temp("beat_count") >= 8 )       
                        call_out("do_recruit", 5, me, fighter);
                else
                        call_out("do_back", 5, me );
        }
        else
        {
                count++;
                call_out("fighting", 2, me, fighter, count);
        }
 
        return 1;
}

int bfighting(object me, object fighter, int count)
{
        object daoshi1, room1, room2, room3;

        if(!( room1 = find_object("/d/lingtai/xiuwu")) )
              room1 = load_object("/d/lingtai/xiuwu");

        if(!( room2 = find_object("/d/lingtai/wuchang")) )
              room2 = load_object("/d/lingtai/wuchang");

        if(!( room3 = find_object("/d/lingtai/yangxin")) )
              room3 = load_object("/d/lingtai/yangxin");

        if(count==0)
            message("vision", HIW"\n八卦阵迅速旋转收拢，\n" NOR, room2);
        if( count <4 ) {
                daoshi1 = present(names[count], room1);
                message("vision", HIW"只见"+daoshi1->query("name")+"吟道："+saywords[count]+"\n"NOR, room2);
                daoshi1->move(room2);

                daoshi1->move(room1);
        }else if( count <8 ) {
                daoshi1 = present(names[count], room3);
                message("vision", HIW"只见"+daoshi1->query("name")+"吟道："+saywords[count]+"\n"NOR, room2);
                daoshi1->move(room2);
                daoshi1->move(room3);
        }
        message("vision", HIW+daoshi1->query("name")+"迅速退回原位！\n" NOR, room2);

        if( !find_player(me->query("assigned_bagua")) ||
        !living(fighter) || fighter->query("kee") <= 1 )
        {
                if( objectp(present(me->query("assigned_bagua"), environment(me)) )) {
                        fighter->delete_temp("fighting");
                        fighter->delete_temp("beat_count");
                }

                say( "云阳真人摇了摇头，说道：想不到 ... 唉！\n\n");
                command("sigh");
                call_out("do_back", 5, me );
        }
        else if( count >= 7 )
        {
                if( (int)fighter->query_temp("beat_count") >= 8 )       
                        call_out("do_recruit", 5, me, fighter);
                else
                        call_out("do_back", 5, me );
        }
        else
        {
                count++;
                call_out("bfighting", 2, me, fighter, count);
        }
 
        return 1;
}


int do_recruit(object me, object fighter)
{
        fighter->delete_temp("beat_count");
        fighter->delete_temp("fighting");
        fighter->add("combat_exp", 5000);
        if(me->query("assigned_sixiang"))fighter->set("sixiang_winner", 1);
        else if(me->query("assigned_bagua"))fighter->set("bagua_winner", 1);

        command("bow");
        say("云阳真人说道：" + RANK_D->query_respect(fighter) + "此番过阵，当对本身修行大有助益，百尺竿头，更进一步，老道就此别过！\n");
        
        call_out("do_back", 2, me );
        return 1;
}

int do_back(object me)
{
        object room;
        
        if(!(room=find_object("/d/lingtai/wuchang")))
            room=load_object("/d/lingtai/wuchang");
        room->set("exits",oldexits);    
        me->delete("assigned_sixiang");
        me->delete("assigned_bagua");
        
        me->move("/d/lingtai/jingtang");

        return 1;
}

