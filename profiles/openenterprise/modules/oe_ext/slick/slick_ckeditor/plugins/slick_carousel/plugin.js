(function() {
  "use strict";

  var CKEDITOR = CKEDITOR || {};

  (function($) {
    CKEDITOR.plugins.add('slick_carousel', {
      lang: 'en',
      requires: 'widget,dialog',
      icons: 'slick_carousel',
      init: function(editor) {
        var maxSlides = 5;

        CKEDITOR.dialog.add('slick_carousel', this.path + 'dialogs/slick_carousel.js');

        // Register the slick_carousel widget.
        var widget = {
          allowedContent: '*',
          requiredContent: 'div(slick_carousel)',
          defaults: function() {
            return {
              slick_carouselId: 'slick_carousel-' + Math.floor((Math.random() * 10000) + 1), // Possible ID collisions!!!
              slides: 3,
              interval: 5000,
              pause: 'hover',
              wrap: "true",
            };
          },
          editables: {},
          parts: {
            indicators: 'ol.slick_carousel-indicators',
            inner: 'div.slick_carousel-inner',
          },
          template: '<div class="slick_carousel slide" data-ride="slick_carousel">' +
            '  <ol class="slick_carousel-indicators">' +
            '    <li data-slide-to="0" class="active"></li>' +
            '    <li data-slide-to="1"></li>' +
            '    <li data-slide-to="2"></li>' +
            '  </ol>' +
            '  <div class="slick_carousel-inner">' +
            '    <div class="item active">' +
            '      <img src="http://placehold.it/1440x500" alt="Slide1">' +
            '      <div class="slick_carousel-caption">' +
            '       <h3>Header 1</h3>' +
            '       <p>Text 1</p>' +
            '       <a href="#" class="btn btn-large btn-info">Read More</a>' +
            '      </div>' +
            '    </div>' +
            '    <div class="item">' +
            '      <img src="http://placehold.it/1440x500" alt="Slide2">' +
            '      <div class="slick_carousel-caption">' +
            '       <h3>Header 2</h3>' +
            '       <p>Text 2</p>' +
            '       <a href="#" class="btn btn-large btn-info">Read More</a>' +
            '      </div>' +
            '    </div>' +
            '    <div class="item">' +
            '      <img src="http://placehold.it/1440x500" alt="Slide3">' +
            '      <div class="slick_carousel-caption">' +
            '       <h3>Header 3</h3>' +
            '       <p>Text 3</p>' +
            '       <a href="#" class="btn btn-large btn-info">Read More</a>' +
            '      </div>' +
            '    </div>' +
            '  </div>' +
            '</div>',
          button: 'Create a Slick Carousel',
          dialog: 'slick_carousel',
          upcast: function(element) {
            if (element.name == 'div' && element.hasClass('slick_carousel')) {
              // Probably a better way of doing this but force all slides to show for now.
              var slick_carousel_inner = element.children[1];
              for (var i = 1; i <= maxSlides - 1; i++) {
                if (slick_carousel_inner.children[i]) {
                  slick_carousel_inner.children[i].attributes.class += ' active';
                }
              }
              return true;
            }
            return false;
          },
          downcast: function(element) {
            // Remove active classes since we don't need those anymore.
            var slick_carousel_inner = element.children[1];
            for (var i = 1; i <= maxSlides - 1; i++) {
              if (slick_carousel_inner.children[i]) {
                var pieces = slick_carousel_inner.children[i].attributes.class.split(' ');
                var id = pieces.indexOf('active');
                if (id >= 0) {
                  pieces.splice(id, 1);
                }
                slick_carousel_inner.children[i].attributes.class = pieces.join(' ');
              }
            }
            return element;
          },
          init: function() {
            if (!this.element.getId()) { // New slick_carousels don't have an id yet.
              this.element.$.id = this.data.slick_carouselId; // There is no exposed method for setId().
              for (var i = 1; i <= maxSlides; i++) {
                if (this.parts['indicator' + i]) {
                  this.parts['indicator' + i].setAttribute('data-target', '#' + this.data.slick_carouselId);
                }
              }
            } else {
              this.setData('slick_carouselId', this.element.getId());
            }
            var that = this;
            var slides = 0;
            for (var j = 1; j <= maxSlides; j++) {
              var slide = this.parts['slide' + j];
              if (slide) {
                slides = j;
                var img = slide.findOne('img');
                if (img) {
                  this.setData('src' + j, img.getAttribute('src'));
                  this.setData('alt' + j, img.getAttribute('alt'));
                }
              }
            }
            this.setData('interval', this.element.getAttribute('data-interval') || '5000');
            this.setData('pause', this.element.getAttribute('data-pause') || 'hover');
            this.setData('wrap', this.element.getAttribute('data-wrap') != "false");
            this.setData('slides', slides);
          },
          data: function() {
            for (var i = 1; i <= maxSlides; i++) {
              if (i <= this.data.slides) {
                // Add any new slides
                if (!this.parts['slide' + i]) {
                  this.parts['indicator' + i] = new CKEDITOR.dom.element('li');
                  this.parts['indicator' + i].setAttribute('data-slide-to', i - 1);
                  this.parts['indicator' + i].setAttribute('data-target', '#' + this.data.slick_carouselId);
                  this.parts.indicators.append(this.parts['indicator' + i]);
                  this.parts['slide' + i] = new CKEDITOR.dom.element('div');
                  this.parts['slide' + i].addClass('item');
                  this.parts['slide' + i].setHtml('<img src="http://placehold.it/1440x500" alt="Slide' + i + '">' +
                    '      <div class="slick_carousel-caption">' +
                    '       <h3>Header ' + i + '</h3>' +
                    '       <p>Text ' + i + '</p>' +
                    '       <a href="#" class="btn btn-large btn-info">Read More</a>' +
                    '      </div>');
                  this.parts.inner.append(this.parts['slide' + i]);
                  this.initEditable('caption' + i, {
                    selector: 'div.slick_carousel-inner div.item:nth-child(' + i + ') div.slick_carousel-caption'
                  });
                  this.parts['img' + i] = this.parts['slide' + i].findOne('img');
                }
                // Make sure active is set during editing so we can see all slides.
                this.parts['slide' + i].addClass('active');
                // Set image properties.
                this.parts['img' + i].setAttribute('src', this.data['src' + i]);
                this.parts['img' + i].removeAttribute('data-cke-saved-src'); // This interferes with things. Not sure what it is supposed to do.
                this.parts['img' + i].setAttribute('alt', this.data['alt' + i]);
              }
              // Remove any extra slides
              else if (i > this.data.slides && this.parts['slide' + i]) {
                this.parts['slide' + i].remove();
                this.parts['slide' + i] = null;
                this.parts['indicator' + i].remove();
                this.parts['indicator' + i] = null;
              }
              if (this.data.interval) {
                this.element.setAttribute('data-interval', this.data.interval);
              } else {
                this.element.removeAttribute('data-interval');
              }
              if (this.data.pause) {
                this.element.removeAttribute('data-pause');
              } else {
                this.element.setAttribute('data-pause', "false");
              }
              if (this.data.wrap) {
                this.element.removeAttribute('data-wrap');
              } else {
                this.element.setAttribute('data-wrap', "false");
              }
            }
          }
        };

        for (var i = 1; i <= maxSlides; i++) {
          widget.editables['caption' + i] = 'div.slick_carousel-inner div.item:nth-child(' + i + ') div.slick_carousel-caption';
          widget.parts['slide' + i] = 'div.slick_carousel-inner div.item:nth-child(' + i + ')';
          widget.parts['img' + i] = 'div.slick_carousel-inner div.item:nth-child(' + i + ') img';
          widget.parts['indicator' + i] = 'ol.slick_carousel-indicators li:nth-child(' + i + ')';
        }

        editor.widgets.add('slick_carousel', widget);
      }
    });
  })(jQuery);

}());