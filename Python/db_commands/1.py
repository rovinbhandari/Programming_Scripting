# import DB2
import 

conn = DB2.connect(dsn='sample', uid='db2inst1', pwd='rovinrovin')
curs = conn.cursor()

curs.execute('select fname, lname from contacts where id=%s'%(id),)

one_row = curs.fetchone()

many_rows = curs.fetchmany(3)

many_rows = curs.fetchall()

curs.execute("insert into contacts values (a, b, c)", (fname, lname, addr) )

curs.close()

conn.close()


