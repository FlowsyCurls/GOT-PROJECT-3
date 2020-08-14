const express = require('express');
const router = express.Router();

const mysqlConnection  = require('../database.js');


// GET all Repositories
router.get('/', (req, res) => {
  mysqlConnection.query('SELECT * FROM repository', (err, rows, fields) => {
    if(!err) {
      res.json(rows);
    } else {
      console.log(err);
    }
  });
});


// GET Repository
router.get('/:id', (req, res) => {
  const { id } = req.params; 
  mysqlConnection.query('SELECT * FROM repository WHERE id = ?', [id], (err, rows, fields) => {
    if (!err) {
      res.json(rows[0]);
    } else {
      console.log(err);
    }
  });
});


// INSERT Repository
router.post('/', (req, res) => {
  const {id, name} = req.body;
  console.log('Inserting: ', id, name);
  const query = `
  SET @id = ?;
  SET @name = ?;
  CALL repositoryAddOrEdit(@id, @name);
`;  mysqlConnection.query(query, [id, name], (err, rows, fields) => {
    if(!err) {
      res.json({status: 'Repository Saved'});
    } else {
      console.log(err);
    }
  });
});


// UPDATE Repository
router.put('/:id', (req, res) => {
  const { name } = req.body;
  const { id } = req.params;
  const query = `
  SET @id = ?;
  SET @name = ?;
  CALL repositoryAddOrEdit(@id, @name);
`;
  mysqlConnection.query(query, [id, name], (err, rows, fields) => {
    if(!err) {
      res.json({status: 'Repository Updated'});
    } else {
      console.log(err);
    }
  });
});


// DELETE Repository
router.delete('/:id', (req, res) => {
  const { id } = req.params;
  mysqlConnection.query('DELETE FROM repository WHERE id = ?', [id], (err, rows, fields) => {
    if(!err) {
      res.json({status: 'Repository Deleted'});
    } else {
      console.log(err);
    }
  });
});

module.exports = router;