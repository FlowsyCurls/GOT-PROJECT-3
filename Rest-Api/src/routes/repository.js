const express = require('express'); // call express
const router = express.Router();

const mysqlConnection  = require('../database.js');


//=======================================            =======================================//
//======================================= REPOSITORY =======================================//
//=======================================            =======================================//


// GET all Repositories
router.get('/repos', (req, res) => {
  mysqlConnection.query('SELECT * FROM Repository', (err, rows, fields) => {
    if(!err) {
      res.json(rows);
      // console.log(rows);
    } else {
      console.log(err);
    }
  });
});

// GET specific Repository
router.get('/repo/:ID', (req, res) => {
  const { ID } = req.params; 
  mysqlConnection.query('SELECT * FROM Repository WHERE id = ?', [ID], (err, rows, fields) => {
    if (!err) {
      res.json(rows[0]);
      // console.log(rows[0]);
    } else {
      console.log(err);
    }
  });
});

// DELETE Repository
router.delete('/repo/:ID', (req, res) => {
  const { ID } = req.params;
  mysqlConnection.query('DELETE FROM Repository WHERE ID = ?', [ID], (err, rows, fields) => {
    if(!err) {
      res.json({status: 'Repository Deleted'});
    } else {
      console.log(err);
    }
  });
});


// INSERT Repository
router.post('/repo', (req, res) => {
  const {ID, Name} = req.body;
  // console.log('Inserting: ', ID, Name);
  const query = `INSERT INTO Repository VALUES(?,?)`;
  mysqlConnection.query(query, [ID, Name], (err, rows, fields) => {
    if(!err) {
      res.json({status: 'Repository Saved'});
    } else {
      console.log(err);
    }
  });
});


// UPDATE Repository
router.put('/repo/:ID', (req, res) => {
  const { Name } = req.body;
  const { ID } = req.params;
  // console.log('Updating: ', ID, Name);
  const query = `UPDATE Repository SET Name = ? WHERE id = ?`;
  mysqlConnection.query(query, [Name, ID], (err, rows, fields) => {
    if(!err) {
      res.json({status: 'Repository Updated'});
    } else {
      console.log(err);
    }
  });
});





//=======================================        =======================================//
//======================================= COMMIT =======================================//
//=======================================        =======================================//


// GET all Commits
router.get('/commits', (req, res) => {
  mysqlConnection.query('SELECT * FROM Commit', (err, rows, fields) => {
    if(!err) {
      res.json(rows);
      // console.log(rows);
    } else {
      console.log(err);
    }
  });
});

// GET specific Commit
router.get('/commit/:comID', (req, res) => {
  const { comID } = req.params; 
  mysqlConnection.query('SELECT * FROM Commit WHERE id = ?', [comID], (err, rows, fields) => {
    if (!err) {
      res.json(rows[0]);
      // console.log(rows[0]);
    } else {
      console.log(err);
    }
  });
});

// DELETE Commit
router.delete('/commit/:comID', (req, res) => {
  const { comID } = req.params;
  mysqlConnection.query('DELETE FROM Repository WHERE id = ?', [comID], (err, rows, fields) => {
    if(!err) {
      res.json({status: 'Commit Deleted'});
    } else {
      console.log(err);
    }
  });
});

// INSERT Commit
router.post('/commit', (req, res) => {
  const {ID, Message, Date} = req.body;
  // console.log('Inserting: ', ID, Message, Date);
  const query = `INSERT INTO Commit VALUES(?,?,?)`;
  mysqlConnection.query(query, [ID, Message, Date], (err, rows, fields) => {
    if(!err) {
      res.json({status: 'Commit Saved'});
    } else {
      console.log(err);
    }
  });
});

// Update Commit
router.put('/commit/:commitID', (req, res) => {
  const { commitID } = req.params;
  const {Message, Date} = req.body;
  // console.log('Updating: ', commitID, Message, Date);
  const query = `UPDATE Commit SET Message = ?, Date = ? WHERE id = ?`;
  mysqlConnection.query(query, [Message, Date, commitID], (err, rows, fields) => {
    if(!err) {
      res.json({status: 'Commit Update'});
    } else {
      console.log(err);
    }
  });
});

//=======================================      ======================================//
//======================================= FILE =======================================//
//=======================================      =======================================//

// GET all File
router.get('/files', (req, res) => {
// router.get('/repo/:repoID/commit/:comID/file', (req, res) => {
  const { comID } = req.params;
  const { repoID } = req.params;
  mysqlConnection.query('SELECT File.* FROM File INNER JOIN Commit on Commit.ID = File.CommitID INNER JOIN Repository on Repository.ID = File.RepositoryID', [comID,repoID], (err, rows, fields) => {
    if(!err) {
      res.json(rows);
      // console.log(rows);
    } else {
      console.log(err);
    }
  });
});


// GET specific File
router.get('/repo/:repoID/commit/:comID/file/:fileID', (req, res) => {
  const { comID } = req.params;
  const { repoID } = req.params;
  const { fileID } = req.params;
  mysqlConnection.query('SELECT File.* FROM File INNER JOIN Commit on Commit.ID = ? INNER JOIN Repository on Repository.ID = ? WHERE `File`.id = ?', [comID, repoID, fileID], (err, rows, fields) => {
    if(!err) {
      res.json(rows);
      console.log(rows);
    } else {
      console.log(err);
    }
  });
});


// DELETE File
router.delete('/repo/:repoID/commit/:comID/file/:fileID', (req, res) => {
  const { comID, repoID, fileID} = req.params;
  mysqlConnection.query('DELETE File.* FROM File INNER JOIN Commit on Commit.ID = ? INNER JOIN Repository on Repository.ID = ? WHERE `File`.id = ?', [comID, repoID, fileID], (err, rows, fields) => {
    if(!err) {
      res.json({status: 'File Deleted'});
    } else {
      console.log(err);
    }
  });
});


// INSERT File
router.post('/repo/:repoID/commit/:comID/file', (req, res) => {
  const {ID, Path, Name, Data} = req.body;
  const { comID, repoID } = req.params;
  console.log('Inserting: ', ID, Path, Name, Data, comID, repoID);
  const query = `INSERT INTO Commit VALUES(?,?,?,?,?,?)`;
  mysqlConnection.query(query, [ID, Path, Name, Data, repoID, comID], (err, rows, fields) => {
    if(!err) {
      res.json({status: 'File Saved'});
    } else { 
      console.log(err);
    }
  });
});

module.exports = router;
