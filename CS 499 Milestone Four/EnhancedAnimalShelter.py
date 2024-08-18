#Victoria Franklin
#SNHU CS 499

from pymongo import MongoClient
from bson.objectid import ObjectId

class AnimalShelter(object):
    """ CRUD operations for Animal collection in MongoDB """

    def __init__(self, username, password):
        
        # Connection Variables
        USER = username
        PASS = password
        HOST = 'nv-desktop-services.apporto.com'
        PORT = 32506
        DB = 'AAC'
        COL = 'animals'
        
        # Initialize Connection
        self.client = MongoClient(f'mongodb://{USER}:{PASS}@{HOST}:{PORT}')
        self.database = self.client[DB]
        self.collection = self.database[COL]

    # Create method to implement the C in CRUD.
    def create(self, data):
        if data is not None:
            insert = self.collection.insert_one(data)  # data should be dictionary and fixed to make use of insert_one rather than the deprecated insert
            if insert.acknowledged:
                return True
            else:
                return False
        else:
            raise Exception("Nothing to save, because data parameter is empty")

    # Read method to implement the R in CRUD.
    def read(self, criteria=None):
        if criteria is not None:
            data = self.collection.find(criteria, {"_id": False})
        else:
            data = self.collection.find({}, {"_id": False})
        
        return list(data)
    
    # Update method to implement the U in CRUD.
    def update(self, initial, change):
        if initial is not None:
            if self.collection.count_documents(initial, limit=1) != 0:
                update_result = self.collection.update_many(initial, {"$set": change})
                return update_result.raw_result # To ensure uniformity, a return statement was included.
            else:
                return "No document was found"
        else:
            raise Exception("Nothing to update, because data parameter is empty")

    # Delete method to implement the D in CRUD.
    def delete(self, remove):
        if remove is not None:
            if self.collection.count_documents(remove, limit=1) != 0:
                delete_result = self.collection.delete_many(remove)
                return delete_result.raw_result # To ensure uniformity, a return statement was included.
            else:
                return "No document was found"
        else:
            raise Exception("Nothing to delete, because data parameter is empty")
