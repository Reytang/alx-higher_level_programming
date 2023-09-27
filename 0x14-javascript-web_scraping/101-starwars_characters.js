#!/usr/bin/node

const request = require('request');
const urlMovie = 'https://swapi-api.alx-tools.com/api/films/' + process.argv[2];

request(urlMovie, async function (error, response, body) {
  const arr = [];

  if (error) {
    console.log(error);
  } else {
    const film = JSON.parse(body);
    for (let c = 0; c < film.characters.length; c++) {
      arr.push(myCharacter(film.characters[c]));
    }
  }

  let actors = await Promise.all(arr);

  actors = actors.map((actor) => JSON.parse(actor).name);
  actors.forEach((actor) => console.log(actor));
});

function myCharacter (thisCharacter) {
  return new Promise((resolve, reject) => {
    request(thisCharacter, function (error, response, body) {
      if (error) {
        reject(error);
      }
      resolve(body);
    });
  });
}
