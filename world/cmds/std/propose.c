// propose.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object who;
	string *wives;
	mapping wiv;

        if(me->query("age") < 17)
           return notify_fail("小孩子一边玩儿去。\n");

        if (!arg) return notify_fail("你要向谁求婚？\n");

        if (me->query("gender")=="女性")
                return notify_fail("只有男人才能向别人求婚！\n");

        if (!objectp(who=present(arg,environment(me))))
                return notify_fail("这里没有这个人。\n");

        if (!who->is_character())
                return notify_fail("想清楚！"+who->name()+"是什么呀！\n");

        if (who==me)
                return notify_fail("开什么玩笑？！？\n");

        if (me->query("married"))
                return notify_fail("嘿嘿，不怕" + me->query("couple/name") + "揍你吗？\n");

        if (!living(who))
                return notify_fail("嗯...你还是先把"+who->name()+"弄醒吧。\n");

        if (who->query("gender")=="男性")
                return notify_fail("嗯？你变态吗？！？\n");

if ((me->query("bonze/class")=="bonze")||(who->query("bonze/class")=="bonze"))
return notify_fail("出家人四大皆空，婚嫁之事就免了吧。\n");

        if (who->query("married"))
                return notify_fail("还是算了吧，"+who->name()+"是有夫之妇啦！\n");
	
        message_vision("$N对着$n拍着胸脯说：只要你嫁给我，你叫我做什么我就做什么！\n", me, who);

        me->set("proposing",1);
        me->set("propose_target", getuid(who));
        who->set("proposed",1);
        who->set("propose_man", getuid(me));

        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : propose <某人>
 
这个指令用来向人求婚，求婚者必须为男性，等女方答应后，双方到月老亭登记，
再完成一定的仪式，就算正式成婚了。

相关指令请参阅：marry
相关程序请参阅：marriage

HELP);
    return 1;
}

