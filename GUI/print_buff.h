/*
Print buffer on text view
*/
void print_buff(Appstate *app_state)
{
	GtkTextIter iter;
	GtkTextMark *mark;	

	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(app_state->text_view));
	mark = gtk_text_buffer_get_insert(buffer);	
	gtk_text_buffer_get_iter_at_mark(buffer,&iter,mark);
	gdk_threads_enter();	
	gtk_text_buffer_insert(buffer,&iter,buff,strlen(buff));

	gtk_text_buffer_get_end_iter(buffer,&iter);
	gtk_text_view_scroll_to_iter(GTK_TEXT_VIEW(app_state->text_view),&iter,0.0,FALSE,0,0);
	gdk_threads_leave();	
			
	bzero(buff,MAXSZ);

}

