import sqlite3 as sq3
from sqlite3 import Error


class Database(object):
    """
    This class represents a database object. It implements
    some methods to ease insertion and query tasks
    """
    def __init__(self, dbname: str):
        """
        This is the constructor of the class
        :param dbname: The name of the database to open
        """
        self.db = None
        self.cursor = None
        self.open_db(dbname)

    def create_dump_table(self, table_name: str = "packages"):
        """
        This method creates a table in the database with the
        name passed as argument
        :param table_name: The name of the table
        """
        query = """CREATE TABLE
                    IF NOT EXISTS """ + table_name + """(
                        type text,
                        serv_id integer,
                        msg_id integer,
                        time text,
                        src integer,
                        des integer,
                        seq integer,
                        status text,
                        info text,
                        rest_of_data json
                    );"""
        self.cursor.execute(query)

    def create_history_table(self, table_name: str = "history"):
        """
        This method creates a table in the database with the
        name passed as argument
        :param table_name: The name of the table
        """
        query = """CREATE TABLE
                    IF NOT EXISTS """ + table_name + """(
                        name text,
                        packets json
                    );"""
        self.cursor.execute(query)

    def open_db(self, db_name: str):
        """
        This method opens the database with the name passed as an argument
        :param db_name: The name of the database to be opened
        """
        try:
            self.db = sq3.connect(db_name)
            self.cursor = self.db.cursor()
        except Error as e:
            print(e)

    def query_db(self, query: str, _list: tuple = None):
        """
        This methods execute a query or an insertion in the db
        :param query: Query using prepared statement
        :param _list: Parameters of the prepared statement
        :return: Results of the query
        """
        if _list is None:
            return self.cursor.execute(query)
        else:
            return self.cursor.execute(query, _list)

    #REVISAR: SE ANADIERON DOS PARÁMETROS MAS A CADA ELEMENTO DE LA TABLA
    #QUE NO TIENEN QUE SER INSERTADOS. ESTOS SON EL INDICE Y EL PAQUETE
    #EN FORMA DE PAQUETE.
    def insert_db(self, query: str, elem):
        """
        This methods execute an insertion in the db
        :param query: Query using prepared statement
        :param elem: Parameters of the prepared statement
        """
        self.cursor.executemany(query, elem)
        self.db.commit()
