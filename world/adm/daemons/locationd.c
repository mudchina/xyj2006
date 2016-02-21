
#define MAPS_DIR __DIR__"maps"
#define LIMIT_LENGTH    60
string replace_long(string long);

varargs mapping random_location(mixed flag)
{
        string line, dir, tmp;
        string *maps, *areas, *files;
        object room;
        mapping location;

        location=allocate_mapping(4);
        line=read_file(MAPS_DIR);
        maps=explode(line, "#####\n");
        do{
                areas=explode(maps[random(sizeof(maps))], "\n");
        } while( flag && areas[0]!="BASE_AREA");
        if(areas[0]=="BASE_AREA")
                areas-=({areas[0]});
        sscanf(areas[0], "[%s]%s", location["area"], dir);
        areas-=({areas[0]});
        files=get_dir(dir);
        do{
                reset_eval_cost();
                do{
                        tmp=files[random(sizeof(files))];
                } while( file_size(dir+tmp)==-2 
                        || !sscanf(tmp, "%*s.c")
                        || catch(call_other(dir+tmp, "???"))
                        || member_array(tmp, areas)!=-1);
                room=find_object(dir+tmp);
                if(!room)
                        room=load_object(dir+tmp);
        }while(!sizeof(room->query("exits"))
                &&!room->query("short"));
        location["file"]=dir+tmp;
        location["room"]=room;
        location["long"]=replace_long(room->query("long"));
        return location;
}

string replace_long(string long)
{
        string tmp="", target="";
        int length, start, i;
        int blank_flag=0;
        
        long=replace_string(long, "\n", "");
        for(i=0;i<strlen(long);i++)
                if(long[i]>160 && long[i]<255)
                        tmp+=long[i..i];
        length=strlen(tmp);
        if(length<LIMIT_LENGTH*2)
                return "";
        start=random(length-LIMIT_LENGTH);
        if(start%2)
                start--;
        length=0;
        for(i=start;i<start+LIMIT_LENGTH;i+=2)
        {
                if(blank_flag<-random(2)-2)
                {
                        target+="¡ö";
                        length++;
                        if(random(2) || length>2)
                        {
                                blank_flag=0;
                                length=0;
                        }
                }
                else
                {
                        blank_flag--;
                        target+=tmp[i..i+1];
                }
        }
        return target;
}
