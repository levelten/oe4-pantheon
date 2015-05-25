Feature: Check demo content
  In order to receive a properly installed site
  As an admin
  I to see the demo content is displaying correctly

  @demo
  Scenario: check homepage
    Given I am an anonymous user
    And I am on the homepage
    Then I should see the text "Attract Visitors"
    And I should see the text "Recent Blogs"

  @demo
  Scenario: check main menu
    Given I am an anonymous user
    And I am on the homepage
    Then I should see the text "Home" in the "navigation" region
    And I should see the text "Services" in the "navigation" region
