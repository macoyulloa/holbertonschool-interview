#!/usr/bin/node

const request = require('request');

try {
  const movieId = process.argv[2];
  const url = `https://swapi.dev/api/films/${movieId}/`;
  request(url, async function (error, response, body) {
    const characters = JSON.parse(body).characters;
    for (const character of characters) {
      const res = await new Promise((resolve, reject) => {
        request(character, (error, res, html) => {
          if (error) {
            reject(error);
          } else {
            resolve(JSON.parse(html).name);
          }
        });
      });
      console.log(res);
    }
  });
} catch (catchErr) {
  console.log(catchErr);
}
