//Cracked by Roath
// backup.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object link_ob;
        string file;
        object* inv;
        int     i, cur_time;

        seteuid(getuid());

        if( !objectp(link_ob = me->query_temp("link_ob")) )
                return notify_fail("你不是经由正常连线进入，不能储存。\n");
                
    cur_time = time();
    if( (cur_time-me->query("last_backup")) < 600 )             
                return notify_fail("你迟点才可以储存。\n");
        
    me->set("last_backup", cur_time);
    
        if( (int)link_ob->save() && (int)me->save() && (int)me->backup()) {
                // backup for fabao

                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); ++i)  {
                   if( inv[i]->query("owner_id") == getuid(me) && 
                   inv[i]->query("series_no") )   {
                           inv[i]->unequip();
                           if( !(int)inv[i]->backup() )   {
                           write("储存失败。\n");
                   write("备份失败。\n");
                           return 0;
                           }
                   }
                }

        write("档案储存完毕。\n");
        write("备份完毕。\n");
                return 1;
        } else {
                write("储存失败。\n");
        write("备份失败。\n");
                return 0;
        }
}

int help(object me)
{
        write(@HELP
指令格式：backup

备份档案。在你的档案遭受莫名其妙的伤害后，可要求巫师恢复。
HELP
        );
        return 1;
}

