int cmd_rusage() {
  mapping u=rusage();
  message("command", "Rusage:\n\
User Time : "+u["utime"]+" ("+u["utime"]/60/60/1000+") hours ("+(u["utime"]/60/1000)%60+") min\n\
System Time : "+u["stime"]+" ("+u["stime"]/60/60/1000+") hours ("+(u["stime"]/60/1000)%60+") min\n\
Minor Faults : "+u["minflt"]+"\n\
Major Faults : "+u["majflt"]+"\n\
"+query_load_average(), this_player());
return 1;
}
