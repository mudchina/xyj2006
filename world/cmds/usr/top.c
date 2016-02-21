#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{
    
    object *list,*ob;
    int i;
    string msg;
    object obj;
    
    seteuid(getuid(me));
        if(arg) {
        if(arg=="me") obj = me;
        else if (wizardp(me)) { obj = present(arg, environment(me));
             if (!obj) obj = find_player(arg);
             if (!obj) obj = find_living(arg);
        if (!obj) return notify_fail("您要察看谁的状态？\n");
        } 
		else return notify_fail("只有巫师才可以察看别人的状态。\n");
         write("你的综合评价：" +get_score(obj)+"\n");
         return 1;}
         
         else{
    ob = filter_array(objects(), (: userp($1) && !wizardp($1) :));
    list = sort_array(ob, (: top_list :));
    msg =  "\n            ┏ "+BCYN HIW+CHINESE_MUD_NAME+"在线高手排行榜"NOR" ┓\n";
    msg += "┏━━━┯━┻━━━━━━━━┯━━━━━┻┯━━━━┓\n";
    msg += "┃ 名次 │    高        手    │ 门     派  │综合评价┃\n";
    msg += "┠───┴──────────┴──────┴────┨\n";
    for (i = 0 ;i < 10 ; i++) {
if( i >= sizeof(list)) 
    msg += "┃暂时空缺。　　　　　　    　　　　　　　　　　　　　┃\n";
        else {
            if( !list[i] ) continue;
            if( !list[i]->query("id") ) continue;
            if(list[i] == me) msg += BBLU HIY;
            msg += sprintf("┃  %-5s %-22s%-14s %5d  ┃\n"NOR,chinese_number(i+1),list[i]->query("name")+"("+
            list[i]->query("id")+")",
            list[i]->query("family")?list[i]->query("family/family_name"):"普通百姓",
            get_score(list[i]));
        }
    }
    msg += "┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
// msg += "  " + NATURE_D->game_time() + "记。\n";
write(HIR"大唐"HIG"盛世"NOR + NATURE_D->game_time() + "记。\n");
    write(msg);
    return 1;
   }
}
int top_list(object ob1, object ob2)
{
    int score1,score2;

    score1 = get_score(ob1);
    score2 = get_score(ob2);

    return score2 - score1;
}

int get_score(object ob)
{
    int tlvl,i,score,number;
    string *ski;
    mapping skills;

    reset_eval_cost();
    skills = ob->query_skills();
    number=sizeof(skills);
    if (!number) return 1; 
    ski  = keys(skills);
    for(i = 0; i<number; i++) {
        tlvl += skills[ski[i]];
    }  // count total skill levels
     score = tlvl/number;
    score += ob->query("max_force")/10;
    score += ob->query("max_mana")/10;
    score += ob->query_str() + ob->query_int() + ob->query_spi() + ob->query_con();
    score += (int)ob->query("combat_exp")/2500;
    score += (int)ob->query("daoxing")/2500;

    return score;
}

int help(object me)
{
write(@HELP
指令格式 : top 
 
这个指令可以让你知道在线十大高手是哪些，别去惹他们。 
top me 查看自己的综合评价。
HELP
    );
    return 1;
}
 



